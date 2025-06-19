#include "ParameterManager.h"
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

bool ParameterManager::Load(const std::string& fp) {
    std::ifstream in(fp);
    if (!in) return false;
    json j; in >> j;
    auto& p = j["parameters"];
    params.wireOffset   = p.value("wireOffset", params.wireOffset);
    params.leadInLength = p.value("leadInLength", params.leadInLength);
    params.taperAngle   = p.value("taperAngle", params.taperAngle);
    return true;
}

bool ParameterManager::Save(const std::string& fp) const {
    json j;
    j["parameters"] = {{"wireOffset", params.wireOffset},
                       {"leadInLength", params.leadInLength},
                       {"taperAngle", params.taperAngle}};
    std::ofstream o(fp);
    if (!o) return false;
    o << j.dump(4);
    return true;
}

const Parameters& ParameterManager::Get() const { return params; }
