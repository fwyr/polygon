#include <iostream>
#include <vector>
#include <structs.hpp>
using namespace std;
vector<vector<Edge>> adj(1000); 
vector<int> pathway;
vector<bool> visited(1000);

bool dfs(const int s) {
    if (visited[s]) return;
    visited[s] = true;
    pathway.push_back(s);

    for (auto u: pathway) {
        cout << u << " ";
    }

    cout << "\n";

    for (auto u: adj[s]) {
        dfs(u.end.name);
    }

    pathway.pop_back();
}


int main() {
    int n, e, a, b, w, x, y, z;
    cout << "Input number of nodes: "; cin >> n;
    cout << "Input number of edges: "; cin >> e;

    vector<Node> nodes(n+2);
    adj = vector<vector<Edge>>(e+2);
    visited = vector<bool>(e+2);

    cout << "For the following nodes, input x, y, and z-coordinates (space-separated).\n";

    for (int i = 1; i <= n; i++) {
        cout << "Node" << i << ": ";
        cin >> x >> y >> z;

        Node cur;
        cur.xcoord = x;
        cur.ycoord = y;
        cur.zcoord = z;

        nodes[i] = cur;
    }

    cout << "For the following edges, start node, end node, and weight (space-separated).\n";

    for (int i = 1; i <= e; i++) {
        cout << "Edge " << i << ": ";
        cin >> a >> b >> w;

        Edge to, from;
        to.end = nodes[b];
        to.weight = w;
        from.end = nodes[a];
        from.weight = w;

        adj[a].push_back(to);
        adj[b].push_back(from);
    }

    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (auto u: adj[i]) {
            cout << "(to " << u.end.name << ", travel " << u.weight << ") ";
        }
        cout << '\n';
    }

    dfs(1);

    return 0;
}