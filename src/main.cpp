/****************************** Module Header ******************************\
    Module Name:  main.cpp
    Project:      Polygon
    Copyright (c) 2022 objected

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
\***************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
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

    // Print out current path
    for (auto u: pathway) {
        std::cout << u << " ";
    }

    std::cout << "\n";

    for (auto u: adj[s]) {
        dfs(u.to.name);
    }

    pathway.pop_back();
}


int main() {
    int n, e, a, b, w;
    std::cout << "Input number of nodes: "; std::cin >> n;
    std::cout << "Input number of edges: "; std::cin >> e;

    std::vector<Node> nodes(n+2);
    adj = std::vector<std::vector<Edge>>(e+2);
    visited = std::vector<bool>(e+2);

    // Input 3-dimensional coordinates for each Node using constructors
    // Point(coordinates.x, coordinates.y, coordinates.z)
    // Node(name, Point)
    std::cout << "For the following nodes, input name, x, y, and z-coordinates (space-separated).\n";

    for (int i = 1; i <= n; i++) {
        double x, y, z;

        std::cout << "Node " << i << ": ";
        std::cin >> x >> y >> z;

        Point p(x, y, z);
        Node current(i, p);

        nodes[i] = current;
    }

    // Input Node and weight for each Edge
    // from(name, Point), to(name, Point)
    // Edge(from, to, weight)
    std::cout << "For the following edges, start node, end node, and weight (space-separated).\n";

    for (int i = 1; i <= e; i++) {
        std::cout << "Edge " << i << ": ";
        std::cin >> a >> b >> w;

        Edge first(nodes[a], nodes[b], w);
        Edge second(nodes[b], nodes[a], w);

        adj[a].push_back(first);
        adj[b].push_back(second);
    }

    // Print out adjacency list
    for (int i = 1; i <= n; i++) {
        std::cout << i << ": ";
        for (auto u: adj[i]) {
            std::cout << "(to " << u.to.name << ", travel " << u.weight << ") ";
        }
        std::cout << '\n';
    }

    return 0;
}