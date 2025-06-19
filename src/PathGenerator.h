#pragma once
#include <vector>
#include "Entity.h"
#include "ParameterManager.h"
#include "Path.h"

class PathGenerator {
public:
    bool Generate(const std::vector<Entity>& entities,
                  const Parameters& params,
                  Path& outPath);
};
