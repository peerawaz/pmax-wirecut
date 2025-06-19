#include "PathGenerator.h"
#include "Clipper.hpp"
using namespace ClipperLib;

bool PathGenerator::Generate(const std::vector<Entity>& entities,
                             const Parameters& params,
                             Path& outPath) {
    Paths input, solution;
    for (auto const& e : entities)
        if (e.type == EntityType::Polyline) {
            PathLib::Path p;
            for (auto const& pt : e.points)
                p.push_back({ pt.x * 1000, pt.y * 1000 });
            input.push_back(p);
        }

    ClipperOffset co;
    co.AddPaths(input, jtRound, etOpenRound);
    co.Execute(solution, params.wireOffset * 1000);

    for (auto const& sol : solution) {
        SegmentList segs;
        for (size_t i=1; i<sol.size(); ++i) {
            Point a{sol[i-1].X/1000.0, sol[i-1].Y/1000.0};
            Point b{sol[i].X/1000.0, sol[i].Y/1000.0};
            segs.emplace_back(a,b);
        }
        outPath.segments.push_back(segs);
    }
    outPath.projectName = "";
    return true;
}
