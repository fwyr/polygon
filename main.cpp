#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> adj[1000];
vector<int> path;
bool visited[1000];
int n, e, a, b, w;

bool dfs(int s) {
    if (visited[s]) return;
    visited[s] = true;
    path.push_back(s);

    for (auto x: path) {
        cout << x << " ";
    }

    cout << "\n";

    for (auto x: adj[s]) {
        dfs(x.first);
    }

    path.pop_back();
}

int main() {
    cout << "Input number of nodes: "; cin >> n;
    cout << "Input number of edges: "; cin >> e;

    cout << "For the following prompts, input start node, end node, and weight (space-separated).\n";

    for (int i = 1; i <= e; i++) {
        cout << "Edge " << i << ": ";
        cin >> a >> b >> w;

        adj[a].push_back(make_pair(b, w));
        adj[b].push_back(make_pair(a, w));
    }

    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (auto x: adj[i]) {
            cout << "(to " << x.first << ", travel " << x.second << ") ";
        }
        cout << '\n';
    }

    dfs(1);

    return 0;
}
