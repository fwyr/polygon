/****************************** Module Header ******************************\
    Module Name:  Node.cpp
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
#include <string>
#include "Node.hpp"

struct Node node;

/*
BELOW CODE IS COMMENTED OUT FOR SAFEKEEPING, LIKELY TO BE REMOVED

class Point {
    public:
        double x;
        double y;
        double z;
        Point(const double &xc, const double &yc, const double &zc) {
            x = xc;
            y = yc;
            z = zc;
        }
};

class Edge {
    public:
        Node from;
        Node to;
        int weight;
        Edge(const Node &a, const Node &b, const int &w) : from(a), to(b), weight(w) {
            from = b;
            to = a;
            weight = w;
        }
};
*/