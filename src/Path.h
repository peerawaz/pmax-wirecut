#pragma once
#include <vector>
#include "Entity.h"

using Segment = std::pair<Point, Point>;
using SegmentList = std::vector<Segment>;

struct Path {
    std::vector<SegmentList> segments;
    std::string projectName;
};
