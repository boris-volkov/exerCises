#ifndef declarations_h
#define declarations_h

#define PI 3.14159265

typedef struct {
    double x;
    double y;
} cartesian_pos_2d_t;

typedef struct {
    double length;
    double theta;
} polar_pos_2d_t;

typedef struct {
    double x;
    double y;
    double z;
} cartesian_pos_3d_t;

typedef struct {
    double length;
    double theta;
    double phi;
} polar_pos_3d_t;

double to_radian(double deg);
double to_degree(double rad);

double cos_deg(double deg);
double acos_deg(double ratio);

double sin_deg(double deg);
double asin_deg(double ratio);

cartesian_pos_2d_t convert_to_2d_cartesian_pos(
        const polar_pos_2d_t* polar_pos);
polar_pos_2d_t convert_to_2d_polar_pos(
        const cartesian_pos_2d_t* cartesian_pos);

cartesian_pos_3d_t convert_to_3d_cartesian_pos(
        const polar_pos_3d_t* polar_pos);
polar_pos_3d_t convert_to_3d_polar_pos(
        const cartesian_pos_3d_t* cartesian_pos);

#endif

