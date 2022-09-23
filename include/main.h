#ifndef SPIROGRAPH_INCLUDE_MAIN_H
#define SPIROGRAPH_INCLUDE_MAIN_H

struct Spirograph{
    double theta; // angle
    double r_i; // inner circle radius
    double r_o; // outer circle radius
    double c_i_dist; // distance from edge of inside circle
    double x;
    double y;
};

void setDefaults(Spirograph &s){
    s.theta = 0;
    s.c_i_dist = 0;
    s.x = 0;
    s.y = 0;
    s.r_i = 0;
    s.r_o = 0;
}


#endif