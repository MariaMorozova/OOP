#pragma once
#include "Body.h"
#include <vector>

#include <algorithm>

CBody* BodyWithTheGreatestWeight(std::vector<CBody*> bodies);
CBody* EasiestBodyInWater(std::vector<CBody*> bodies);

