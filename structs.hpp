#include <iostream>
struct Node {
    int name;
    int xcoord;
    int ycoord;
    int zcoord;
};

struct Edge {
    Node end;
    int weight;
};