/****************************** Module Header ******************************\
    Module Name:  Graph.hpp
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

#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "Node.hpp"

class Graph {
    public:
        std::map<std::string, Node> nodes;
        // Adjacency list
        std::map<std::string, std::vector<std::pair<Node, double>>> adj;
        std::tuple<double, double, double> line;
        void add_edge(Node current, Node neighbour, double weight, bool is_directed);
        void print_graph();
        void calculate_line(Node start, Node end);
};