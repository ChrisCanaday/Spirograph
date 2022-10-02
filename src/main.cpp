#include <cstdio>
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>

#include "../include/main.h"
using namespace std;

void printUsage();
void printPrompt();

int main(int argc, char **argv){
    Spirograph graph;

    graph.getInput(argc, argv);

    return 0;
}

void Spirograph::getInput(int arc, char **argv){
    string s;
    int R_O, R_I;
    double p;

    // get input
    while(getline(cin,s)){
        stringstream ss(s);
        graph_data g;

        // read in all the parameters
        ss >> g.colors.r >> g.colors.g >> g.colors.b >> g.r_o >> g.r_i >> g.rho >> g.starting_theta >> g.starting_pos >> g.fill;

        // add it to the list of spirographs to make
        spiro.push_back(g);
    }

    // draw the spirograph
    createSpiroGraph();
}

void graph_data::draw(){
    int i,n,lcm;
    double t,it,step,maxt,tmp,diff;
    
    // find the least common multiple
    lcm = r_o*r_i / __gcd(r_o,r_i);

    // number of loops requred to complete spirograph
    n = lcm / r_o;
    
    // calculate the maximum angle to complete the spirograph
    // over estimate pi so that it properly completes
    maxt = n * 2 * 3.2;

    // designate how many radians to iterate by
    it = .01;

    // start the line set color and add the points

    if(fill == 1){
        printf("newline poly color %d %d %d pcfill %d %d %d\n",colors.r,colors.g,colors.b,colors.r,colors.g,colors.b);
    }else{
        printf("newline color %d %d %d\n",colors.r,colors.g,colors.b);
    }
    printf("pts\n");

    // set the start
    t = 0.0;

    // get the reused variables
    tmp = (double) (r_o - r_i)/ (double)r_i;
    diff = (double) r_o - (double) r_i;

    // print all of the points for the spirograph on stdout
    // first cos is the position of the inside circle
    // second cos is the position of the point inside the inside circle
    while(t <= maxt){
        x = diff * cos(t+starting_theta) + rho * cos(tmp*t+starting_pos);
        y = diff * sin(t+starting_theta) - rho * sin(tmp*t+starting_pos);

        printf("%.5lf %.5lf\n",x,y);
        t += it;
    }
}

void Spirograph::createSpiroGraph(){
    unsigned int i, maxr_o;
    maxr_o = 0;

    // find the biggest spirograph (Use it to designate the size of the canvas)
    for(i = 0; i < spiro.size(); i++){
        if(maxr_o < spiro[i].r_o){
            maxr_o = spiro[i].r_o;
        }
    }

    // create the graph and set the axes
    printf("newgraph\n");
    printf("xaxis min %d max %d nodraw\n",-1*maxr_o+1,1*maxr_o+1);
    printf("yaxis min %d max %d nodraw\n",-1*maxr_o+1,1*maxr_o+1);

    // draw all the spirographs
    for(i = 0; i < spiro.size(); i++) spiro[i].draw();
}