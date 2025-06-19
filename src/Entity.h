#pragma once
#include <vector>

enum class EntityType { Line, Polyline, Circle, Arc };
struct Point { double x, y; };

struct Entity {
    EntityType type;
    std::vector<Point> points;
};
