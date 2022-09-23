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
    int gcd;

    while(getline(cin,s)){
        stringstream ss(s);

        ss >> colors.r >> colors.g >> colors.b >> outerteethcount >> innerteethcount >> rho;
        //gcd();
        gcd = __gcd(outerteethcount,innerteethcount);
        r_o = outerteethcount / gcd;
        r_i = outerteethcount / gcd;
        createSpiroGraph();
    }
}

void Spirograph::draw(){
    int i,n;
    double t,it,step;
    
    n = 2000 * r_o;

    //n = 2000;
    it = r_o * 3.1459 * 2 / n;

    printf("newline color %d %d %d\n",colors.r,colors.g,colors.b);
    printf("pts\n");

    t = 0.0;
    for(i = 0; i < n; i++){
        x = r_o*((1-k)*cos(t) + l*k*cos(((1-k)/k) * t));
        y = r_o*((1-k)*sin(t) - l*k*sin(((1-k)/k) * t));
        printf("%.3lf %.3lf\n",x,y);
        t += it;
    }
}

void Spirograph::createSpiroGraph(){
    printf("newgraph\n");
    //printf("xaxis min %lf max %lf nodraw\n", -1*(r_o+1),r_o+1);
    //printf("yaxis min %lf max %lf nodraw\n", -1*(r_o+1),r_o+1);
    printf("xaxis nodraw\n");
    printf("yaxis nodraw\n");

    draw();
}