#pragma once
#include <string>
#include <vector>
#include "Entity.h"

class ImportManager {
public:
    bool ImportDXF(const std::wstring& path, std::vector<Entity>& outEntities);
};
