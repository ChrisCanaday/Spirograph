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

    graph.setDefaults();
    graph.getInput(argc, argv);

    //graph.createSpiroGraph();
    //graph.draw();

    return 0;
}

void Spirograph::getInput(int arc, char **argv){
    string s;

    printf("newgraph\n");
    printf("xaxis min %d max %d nodraw\n",-2*r_o,2*r_o);
    printf("yaxis min %d max %d nodraw\n",-2*r_o,2*r_o);

    /*while(getline(cin,s)){
        stringstream ss(s);

        ss >> colors.r >> colors.g >> colors.b >> r_o >> r_i >> rho;
        createSpiroGraph();
    }*/
    setDefaults();
    createSpiroGraph();
}

void Spirograph::draw(){
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
    printf("newline color %d %d %d\n",colors.r,colors.g,colors.b);
    printf("pts\n");

    // set the start
    t = 0.0;

    // get the reused variables
    tmp = (double) (r_o - r_i)/ (double)r_i;
    diff = (double) r_o - (double) r_i;

    // print all of the points for the spirograph on stdout
    while(t <= maxt){
        x = diff * cos(t) + rho * cos(tmp*t);
        y = diff * sin(t) - rho * sin(tmp*t);

        printf("%.5lf %.5lf\n",x,y);
        t += it;
    }
}

void Spirograph::createSpiroGraph(){
    //printf("newgraph\n");
    //printf("xaxis min %lf max %lf nodraw\n", -1*(r_o+1),r_o+1);
    //printf("yaxis min %lf max %lf nodraw\n", -1*(r_o+1),r_o+1);
    //printf("xaxis nodraw\n");
    //printf("yaxis nodraw\n");

    draw();
}