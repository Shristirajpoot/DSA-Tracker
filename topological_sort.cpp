// topological_sort.cpp
// Topological Sort using Kahn's Algorithm (BFS approach)

#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;  
    vector<vector<int>> adj;  

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    vector<int> topologicalSort() {
        vector<int> inDegree(V, 0);

        // Calculate in-degree of each node
        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                inDegree[v]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) q.push(i);
        }

        vector<int> topoOrder;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topoOrder.push_back(u);

            for (int v : adj[u]) {
                if (--inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        if (topoOrder.size() != V) {
            cout << "Cycle detected! Topological sort not possible.\n";
            return {};
        }

        return topoOrder;
    }
};

int main() {
    int V = 6;
    Graph g(V);

    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    vector<int> topo = g.topologicalSort();

    cout << "Topological Order: ";
    for (int node : topo) cout << node << " ";
    cout << "\n";

    return 0;
}
