#include <math.h>
#include "utils.h"

float Utils::getAlpha(Point<float> iniPos, Point<float> endPos){
    float alpha;
    float aux = (endPos.getx() - iniPos.getx()) / (endPos.gety() - iniPos.gety());
    alpha = atan( aux );

    return alpha;
}
