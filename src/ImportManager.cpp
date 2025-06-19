#include "ImportManager.h"
#include "drw_interface.h"
#include "drw_entities.h"
#include <codecvt>

static std::string utf8(const std::wstring& w) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
    return conv.to_bytes(w);
}

class DXFHandler : public DRW_Interface {
public:
    std::vector<Entity>& entities;
    DXFHandler(std::vector<Entity>& e): entities(e) {}
    void addLine(const DRW_Line& line) override {
        Entity ent{EntityType::Line};
        ent.points = {{line.basePoint.x, line.basePoint.y},
                      {line.secPoint.x, line.secPoint.y}};
        entities.push_back(ent);
    }
    void addPolyline(const DRW_Polyline& pl) override {
        Entity ent{EntityType::Polyline};
        for (auto const& v : pl.vertexes)
            ent.points.push_back({v.x, v.y});
        entities.push_back(ent);
    }
};

bool ImportManager::ImportDXF(const std::wstring& path, std::vector<Entity>& outEntities) {
    if (path.substr(path.find_last_of(L'.')) != L".dxf") return false;
    DXFHandler handler(outEntities);
    drw_interface reader(&handler, nullptr, nullptr, nullptr);
    if (!reader.readFile(utf8(path))) return false;
    return !outEntities.empty();
}
