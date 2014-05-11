#include <math.h>
#include "utils.h"

float getAlpha(int x1, int y1, int x2, int y2){
    float alpha;
    float aux = (x2 - x1) / (y2 - y1);
    alpha = atan( aux );

    return alpha;
}
