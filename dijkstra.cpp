#include <bits/stdc++.h>
using namespace std;

/*
   Dijkstra's Algorithm
   ---------------------
   Finds shortest path from a source node to all other nodes
   in a weighted graph (non-negative weights).

   Complexity: O((V + E) log V) with priority_queue
*/

typedef pair<int,int> pii;

vector<int> dijkstra(int n, vector<vector<pii>> &adj, int src) {
    vector<int> dist(n+1, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[src] = 0;
    pq.push({0, src});  // {distance, node}

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d != dist[u]) continue; // outdated entry

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, src;
    cin >> n >> m >> src; // nodes, edges, source

    vector<vector<pii>> adj(n+1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove if directed graph
    }

    vector<int> dist = dijkstra(n, adj, src);

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) cout << "Node " << i << ": INF\n";
        else cout << "Node " << i << ": " << dist[i] << "\n";
    }

    return 0;
}
