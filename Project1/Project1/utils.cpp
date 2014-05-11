#include <math.h>
#include "utils.h"
#include "Point.h"

float getAlpha(Point<float> iniPos, Point<float> endPos){
    float alpha;
    float aux = (endPos.getx() - iniPos.getx()) / (endPos.gety() - iniPos.gety());
    alpha = atan( aux );

    return alpha;
}
