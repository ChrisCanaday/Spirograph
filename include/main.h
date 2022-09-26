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
    //double l; // rho / r_i  represents how far some point A is from the center of inner circle
    //double k; // r_i / r_o  represents size of inner circle with respect to outer circle
    color colors;
    int rotations;
    int outerteethcount;
    int innerteethcount;

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
    rho = .5;
    //l = rho / r_i;
    //k = (double) r_i / (double) r_o;
    colors.r = 0;
    colors.g = 0;
    colors.b = 0;
    outerteethcount = 20;
    innerteethcount = 5;
}


#endif