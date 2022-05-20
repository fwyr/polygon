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
#include "Coordinates.hpp"
#include "Node.hpp"
#include "Graph.hpp"

std::map<std::string, bool> visited;
std::vector<std::string> pathway;
Graph g;

void clear() {
    std::cout << "\x1B[2J\x1B[H"; // clears terminal
}

void dfs(const std::string &s) {
    if (visited[s]) return;
    visited[s] = true;
    pathway.push_back(s);
    std::map<std::string, std::vector<std::pair<Node, double>>> l = g.adj;

    // Print out current path
    for (auto u: pathway) {
        std::cout << u << " ";
    }

    std::cout << "\n";

    for (auto val: l) {
        std::string name = val.first;
        std::vector<std::pair<Node, double>> neighbours = val.second;
        for (auto u: neighbours) {
            Node neighbour = u.first;
            dfs(neighbour.name);
        }
    }

    pathway.pop_back();
}

int main() {
    clear();

    // Input number of nodes
    int n;
    std::cout << "Input number of nodes: ";
    std::cin >> n;
    clear();

    // Input number of edges
    int e;
    std::cout << "Input number of edges: ";
    std::cin >> e;
    clear();

    // Input 3-dimensional coordinates and store nodes
    std::cout << "For the following nodes, input name, x, y, and z-coordinates (4 space-separated inputs).\n";
    for (int i = 1; i <= n; i++) {
        std::string s;
        double x, y, z;
        std::cout << "Node " << i << ": ";
        std::cin >> s >> x >> y >> z;

        Coordinates p;
        p.x_coordinate = x;
        p.y_coordinate = y;
        p.z_coordinate = z;

        Node cur;
        cur.name = s;
        cur.point = p;

        g.nodes[s] = cur;
    }
    clear();

    // Input Node name and calculate weight for each Edge
    std::cout << "For the following edges, input the name of the start node and end node (2 space-separated inputs).\n";
    for (int i = 1; i <= e; i++) {
        std::string a, b;
        std::cout << "Edge " << i << ": ";
        std::cin >> a >> b;

        Node first = g.nodes[a];
        Node second = g.nodes[b];

        double run = abs(second.point.x_coordinate - first.point.x_coordinate);
        double rise = abs(second.point.y_coordinate - first.point.y_coordinate);
        double weight = std::hypot(run, rise);

        g.add_edge(first, second, weight, false);
    }
    clear();

    // Input start Node and end Node
    std::cout << "Input the starting node and the ending node (2 space-separated inputs).\n";
    std::string start_node_str, end_node_str;
    std::cin >> start_node_str >> end_node_str;
    Node start_node = g.nodes[start_node_str];
    Node end_node = g.nodes[end_node_str];
    clear();
    
    // Do some graphies
    g.calculate_line(start_node, end_node);

    std::cout << "Print adjacency list:\n";
    g.print_graph();

    std::cout << "\nPrint traversal of DFS:\n";
    dfs("one");

    std::cout << "\nEnd of output.";

    return 0;
}