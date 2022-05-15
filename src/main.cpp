#include <iostream>
#include <vector>
#include <queue>
// Edge.end, Edge.weight
// Node.coords, Node.name
// Coordinates.x, Coordinates.y, Coordinates.z
#include "Edge.hpp"

// Global variable declarations
std::vector<std::vector<Edge>> adj(1000); 
std::vector<bool> visited(1000);
std::vector<int> pathway;

// Depth-first search, print pathways
void dfs(const int s) {
    if (visited[s]) return;
    visited[s] = true;
    pathway.push_back(s);

    for (auto u: pathway) {
        std::cout << u << " ";
    }

    std::cout << "\n";

    for (auto u: adj[s]) {
        dfs(u.end.name);
    }

    pathway.pop_back();
}


int main() {
    int n, e, a, b, w;
    double x, y, z;
    std::cout << "Input number of nodes: "; std::cin >> n;
    std::cout << "Input number of edges: "; std::cin >> e;

    std::vector<Node> nodes(n+2);
    adj = std::vector<std::vector<Edge>>(e+2);
    visited = std::vector<bool>(e+2);

    // Input Vec3 coordinates for each Node (coords.x, coords.y, coords.z)
    std::cout << "For the following nodes, input x, y, and z-coordinates (space-separated).\n";

    for (int i = 1; i <= n; i++) {
        std::cout << "Node " << i << ": ";
        std::cin >> x >> y >> z;

        Node cur;
        cur.name = i;
        cur.coords.x = x;
        cur.coords.y = y;
        cur.coords.z = z;

        nodes[i] = cur;
    }

    // Input 'from' node and weight for each Edge (to.end, to.weight, from.end, from.weight)
    std::cout << "For the following edges, start node, end node, and weight (space-separated).\n";

    for (int i = 1; i <= e; i++) {
        std::cout << "Edge " << i << ": ";
        std::cin >> a >> b >> w;

        Edge to, from;
        to.end = nodes[b];
        to.weight = w;
        from.end = nodes[a];
        from.weight = w;

        adj[a].push_back(to);
        adj[b].push_back(from);
    }

    // Print out adjacency list
    for (int i = 1; i <= n; i++) {
        std::cout << i << ": ";
        for (auto u: adj[i]) {
            std::cout << "(to " << u.end.name << ", travel " << u.weight << ") ";
        }
        std::cout << '\n';
    }

    return 0;
}