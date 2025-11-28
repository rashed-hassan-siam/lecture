#include <iostream>
#include <vector>

using namespace std;

void dfsUtil(int u, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    cout << u << " ";

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfsUtil(v, adj, visited);
        }
    }
}

void dfs(const vector<vector<int>>& adj, int start_node) {
    vector<bool> visited(adj.size(), false);
    dfsUtil(start_node, adj, visited);
}

int main() {
    int V = 4;
    vector<vector<int>> adj(V);
    adj[0] = {1, 2};
    adj[1] = {2};
    adj[2] = {0, 3};
    adj[3] = {3};

    cout << "DFS starting from vertex 2: ";
    dfs(adj, 2);
    cout << endl;
    return 0;
}