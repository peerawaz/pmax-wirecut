#include "ExportManager.h"
#include <fstream>
#include <inja/inja.hpp>

bool ExportManager::ExportGCode(const std::string& outputPath, const Path& path) {
    inja::Environment env;
    inja::json ctx;
    ctx["projectName"] = path.projectName;

    std::ofstream out(outputPath);
    out << env.render("(001) PROJECT {{ projectName }}", ctx) << std::endl;
    for (auto const& segs : path.segments)
        for (auto const& s : segs) {
            ctx["x"] = s.second.x;
            ctx["y"] = s.second.y;
            ctx["z"] = 0;
            out << env.render("G01 X{{ x }} Y{{ y }} Z{{ z }}", ctx) << std::endl;
        }
    out << "(999) END OF PROGRAM" << std::endl;
    return true;
}
