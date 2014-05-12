#ifndef _UTILS_H_
#define _UTILS_H_

#include "Point.h"
#include <math.h>

using namespace std;

class Utils {
    public :
        float getAlpha(Point<float> iniPos, Point<float> endPos);
};

#endif