#ifndef SPIROGRAPH_INCLUDE_MAIN_H
#define SPIROGRAPH_INCLUDE_MAIN_H

#include <string>

struct color{
    int r;
    int g;
    int b;
};

struct Spirograph{
    int r_i; // inner circle radius
    int r_o; // outer circle radius
    double x; // x position
    double y; // y position
    double rho; // distance from center of inner circle (the point)
    color colors;

    void setDefaults();
    void getInput(int arc, char **argv);
    void draw();
    void createSpiroGraph();
};

void Spirograph::setDefaults(){
    x = 0;
    y = 0;
    r_i = 1;
    r_o = 2;
    rho = .9;
    colors.r = 0;
    colors.g = 0;
    colors.b = 0;
}


#endif