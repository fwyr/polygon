#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, e; 
    cout << "Input number of nodes: "; cin >> n;
    cout << "Input number of edges: "; cin >> e;

    vector<pair<int, int>> g[e+5];

    cout << "For the following prompts, input start node, end node, and weight (space-separated).";

    for (int i = 1; i <= e; i++) {
        int a, b, w; 
        cout << "Edge " << i << ": ";
        cin >> a >> b >> w;

        g[a].push_back(make_pair(b, w));
        g[b].push_back(make_pair(a, w));
    }

    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (auto x: g[i]) {
            cout << "(to " << x.first << ", travel " << x.second << ") ";
        }
        cout << '\n';
    }

    return 0;
}
