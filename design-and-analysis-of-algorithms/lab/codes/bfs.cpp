#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(const vector<vector<int>>& adj, int start_node) {
    vector<bool> visited(adj.size(), false);
    queue<int> q;

    visited[start_node] = true;
    q.push(start_node);

    while (!q.empty()) {
        int u = q.front();
        cout << u << " ";
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    int V = 4;
    vector<vector<int>> adj(V); // Adjacency list
    adj[0] = {1, 2};
    adj[1] = {2};
    adj[2] = {0, 3};
    adj[3] = {3};

    cout << "BFS starting from vertex 2: ";
    bfs(adj, 2);
    cout << endl;
    return 0;
}