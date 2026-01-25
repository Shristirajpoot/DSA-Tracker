#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int LOG = 20; // For up to 2^20 nodes
vector<int> tree[MAXN];
int up[MAXN][LOG]; // up[v][j] = 2^j-th ancestor of node v
int depth[MAXN];

// DFS to initialize up table and depth
void dfs(int v, int parent) {
    up[v][0] = parent;
    for(int i = 1; i < LOG; i++) {
        if(up[v][i-1] != -1)
            up[v][i] = up[up[v][i-1]][i-1];
        else
            up[v][i] = -1;
    }
    for(int u : tree[v]) {
        if(u != parent) {
            depth[u] = depth[v] + 1;
            dfs(u, v);
        }
    }
}

// Function to get LCA of nodes u and v
int lca(int u, int v) {
    if(depth[u] < depth[v]) swap(u, v);

    // Bring u to the same depth as v
    int diff = depth[u] - depth[v];
    for(int i = 0; i < LOG; i++) {
        if(diff & (1 << i)) {
            u = up[u][i];
        }
    }

    if(u == v) return u;

    for(int i = LOG-1; i >= 0; i--) {
        if(up[u][i] != -1 && up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }

    return up[u][0];
}

int main() {
    int n, q;
    cin >> n >> q; // Number of nodes and queries

    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v; // Edge between u and v
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    memset(up, -1, sizeof(up));
    depth[1] = 0; // Assuming 1 is root
    dfs(1, -1);

    while(q--) {
        int u, v;
        cin >> u >> v;
        cout << "LCA of " << u << " and " << v << " is " << lca(u, v) << "\n";
    }

    return 0;
}
