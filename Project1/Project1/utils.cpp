#include "utils.h"

float Utils::getAlpha(Point<float> iniPos, Point<float> endPos){
    float alpha;
    alpha = atan2f(endPos.gety() - iniPos.gety(), endPos.getx() - iniPos.getx());
    return alpha;
}
