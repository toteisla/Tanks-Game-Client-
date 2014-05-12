#include <math.h>
#include "utils.h"

float Utils::getAlpha(Point<float> iniPos, Point<float> endPos){
    float alpha;
    alpha = atan2f( (endPos.getx() - iniPos.getx()), (endPos.gety() - iniPos.gety()));
    return alpha;
}
