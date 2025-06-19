#pragma once
#include <string>
#include "Entity.h"

struct Parameters { double wireOffset=0.05, leadInLength=1.0, taperAngle=2.0; };

class ParameterManager {
public:
    bool Load(const std::string& filepath);
    bool Save(const std::string& filepath) const;
    const Parameters& Get() const;
private:
    Parameters params;
};
