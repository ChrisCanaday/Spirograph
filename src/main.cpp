#include <cstdio>
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <numeric>

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
    int gcd;
    printf("newgraph\n");
    printf("xaxis nodraw\n");
    printf("yaxis nodraw\n");

    /*while(getline(cin,s)){
        stringstream ss(s);

        ss >> colors.r >> colors.g >> colors.b >> r_o >> r_i >> rho;
        //gcd();
        *//*gcd = __gcd(outerteethcount,innerteethcount);
        r_o = outerteethcount / gcd;
        r_i = outerteethcount / gcd;*//*
        l = rho / r_i;
        k = r_i / r_o;
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

    // number of loops requred to complete spriograph
    // http://mathadinfinitum.weebly.com/the-math-of-spirographs.html
    n = lcm / r_o;
    
    // over estimate pi so that it for sure completes
    maxt = n * 2 * 3.2;

    it = .01;

    printf("newline color %d %d %d\n",colors.r,colors.g,colors.b);
    printf("pts\n");

    t = 0.0;
    // https://sciencedemos.org.uk/spirograph.php

    tmp = (double) (r_o - r_i)/ (double)r_i;
    diff = (double) r_o - (double) r_i;
    //printf("%lf\n",rho);
    while(t <= maxt){
        x = diff * cos(t) + rho * cos(tmp*t);
        y = diff * sin(t) - rho * sin(tmp*t);

        printf("%.3lf %.3lf\n",x,y);
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