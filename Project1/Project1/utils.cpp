#include <math.h>
#include "utils.h"

float Utils::getAlpha(Point<float> iniPos, Point<float> endPos){
    float alpha;
    float aux = (endPos.gety() - iniPos.gety()) / (endPos.getx() - iniPos.getx());
    //alpha = atan( aux );
    alpha = atan2(((float)(endPos.gety() - iniPos.gety())), ((float)(endPos.getx() - iniPos.getx())));

    return alpha;
}
