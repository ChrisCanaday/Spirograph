#ifndef SPIROGRAPH_INCLUDE_MAIN_H
#define SPIROGRAPH_INCLUDE_MAIN_H

#include <iostream>
#include <string>
#include <vector>

struct color{
    int r;
    int g;
    int b;
};

struct graph_data{
    int r_i; // inner circle radius
    int r_o; // outer circle radius
    double x; // x position
    double y; // y position
    double rho; // distance from center of inner circle (the point)
    double starting_theta; // starting position of the circle
    double starting_pos; // starting position of the point
    color colors; // the color values

    void draw();
};

struct Spirograph{
    std::vector<graph_data> spiro;

    //void setDefaults();
    void getInput(int arc, char **argv);
    //void draw();
    void createSpiroGraph();
};

/*void Spirograph::setDefaults(){
    x = 0;
    y = 0;
    r_i = 30;
    r_o = 90;
    rho = 5;
    colors.r = 0;
    colors.g = 0;
    colors.b = 0;
}*/


#endif