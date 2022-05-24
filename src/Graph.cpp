/****************************** Module Header ******************************\
    Module Name:  Graph.cpp
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
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include "Node.hpp"
#include "Graph.hpp"

void Graph::add_edge(Node current, Node neighbour, double weight, bool is_directed = false) {
    adj[current.name].push_back(std::make_pair(neighbour, weight));

    // Graph is expected to be undirected but extra parameter is added in case of unforeseen circumstances
    // is_directed marked as false by default
    // If the edge is directed, we will not add the edge to the neighbouring vector
    if (!is_directed) {
        adj[neighbour.name].push_back(std::make_pair(current, weight));
    }
}

void Graph::print_graph() {
    // Iterate over all keys in the adjacency list map
    // Print list of neighbours associated with these nodes
    for (auto val: adj) {
        // Iterate over all neighbours of node 'current'
        std::string name = val.first;
        std::vector<std::pair<Node, double>> neighbours = val.second;

        std::cout << name << ": ";

        for (auto u: neighbours) {
            Node destination = u.first;
            double weight = u.second;
            std::cout << "(to: " << destination.name << ", weight: " << weight << ")";
        }

        std::cout << "\n";
    }
}

void Graph::calculate_line(Node start, Node end) {
    double m_A = start.point.y_coordinate - end.point.y_coordinate;
    double m_B = end.point.x_coordinate - start.point.x_coordinate;
    double m_C = start.point.x_coordinate * end.point.y_coordinate - end.point.x_coordinate * start.point.y_coordinate;

    if (m_A == 0 && m_B == 0) {
        std::cout << "Line error: A & B = 0";
    }

    std::tuple<double, double, double> linevalues = std::make_tuple(m_A, m_B, m_C);

    Graph::line = linevalues;
}

double Graph::distance_point_to_line(Node n) {
    Coordinates p = n.point;
    double m_A = std::get<0>(Graph::line);
    double m_B = std::get<1>(Graph::line);
    double m_C = std::get<2>(Graph::line);
    return abs(m_A * p.x_coordinate + m_B * p.y_coordinate + m_C) / std::hypot(m_A, m_B);
}