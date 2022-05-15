#pragma once
#include <iostream>

struct Coordinates {
    double x;
    double y;
    double z;
};

struct Node {
    int name;
    Coordinates coords;
};

struct Edge {
    Node end;
    int weight;
};