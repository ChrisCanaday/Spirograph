#ifndef SPIROGRAPH_INCLUDE_MAIN_H
#define SPIROGRAPH_INCLUDE_MAIN_H

#include <iostream>
#include <string>
#include <vector>

struct color{
    int r; // red value
    int g; // green value
    int b; // blue value
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

    void getInput(int arc, char **argv);
    void createSpiroGraph();
};

#endif