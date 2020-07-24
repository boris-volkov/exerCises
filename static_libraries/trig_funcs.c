#include <math.h>

// header included to use the macro PI
#include "declarations.h"

double to_radian(double deg) {
    return (PI * deg) / 180;
}

double to_degree(double rad) {
    return (rad * 180) / PI;
}

double cos_deg(double deg) {
    return cos(to_radian(deg));
}

double acos_deg(double ratio) {
    return to_degree(acos(ratio));
}

double sin_deg(double deg) {
    return sin(to_radian(deg));
}

double asin_deg(double ratio) {
    return to_degree(asin(ratio));
}

