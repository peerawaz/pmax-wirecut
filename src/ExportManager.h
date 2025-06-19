#pragma once
#include <string>
#include "Path.h"

class ExportManager {
public:
    bool ExportGCode(const std::string& outputPath, const Path& path);
};
