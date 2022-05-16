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

#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include "Node.hpp"
#include "Graph.hpp"
using namespace std;

std::map<std::string, Node> nodes;
std::map<std::string, bool> visited;
std::vector<std::string> pathway;
Graph g;

void dfs(const std::string &s) {
    if (visited[s]) return;
    visited[s] = true;
    pathway.push_back(s);
    map<std::string, vector<pair<Node, double>>> l = g.adj;

    // Print out current path
    for (auto u: pathway) {
        std::cout << u << " ";
    }

    std::cout << "\n";

    for (auto val: l) {
        string name = val.first;
        vector<pair<Node, double>> neighbours = val.second;
        for (auto u: neighbours) {
            Node neighbour = u.first;
            dfs(neighbour.name);
        }
    }

    pathway.pop_back();
}

int main() {
    // Input number of nodes
    int n;
    std::cout << "Input number of nodes: ";
    std::cin >> n;

    // Input number of edges
    int e;
    std::cout << "Input number of edges: ";
    std::cin >> e;

    // Input 3-dimensional coordinates and store nodes
    std::cout << "For the following nodes, input name, x, y, and z-coordinates "
                 "(4 space-separated inputs).\n";
    for (int i = 1; i <= n; i++) {
        std::string s;
        double x, y, z;
        std::cout << "Node " << i << ": ";
        std::cin >> s >> x >> y >> z;

        Node cur;
        cur.name = s;
        cur.x_coordinate = x;
        cur.y_coordinate = y;
        cur.z_coordinate = z;

        nodes[s] = cur;
    }

    // Input Node name and calculate weight for each Edge
    std::cout << "For the following edges, input the name of the start node "
                 "and end node (2 space-separated inputs).\n";
    for (int i = 1; i <= e; i++) {
        std::string a, b;
        std::cout << "Edge " << i << ": ";
        std::cin >> a >> b;

        Node first = nodes[a];
        Node second = nodes[b];

        double run = abs(second.x_coordinate - first.x_coordinate);
        double rise = abs(second.y_coordinate - first.y_coordinate);
        double weight = std::hypot(run, rise);

        g.add_edge(first, second, weight, false);
    }

    g.print_graph();

    // dfs("one");

    return 0;
}
