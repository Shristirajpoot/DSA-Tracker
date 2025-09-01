#include <bits/stdc++.h>
using namespace std;

/*
  Min-Cost Max-Flow (Successive Shortest Augmenting Path with Potentials)
  ---------------------------------------------------------------------
  - Works with negative costs (no negative cycles reachable).
  - Uses Dijkstra + Johnson potentials for O(F * (M log N)) on sparse graphs.
  - 64-bit costs and capacities.

  API:
    MinCostMaxFlow g(n);
    g.add_edge(u, v, cap, cost); // directed edge
    auto [flow, cost] = g.min_cost_max_flow(s, t, max_flow = INF);

  Example Input:
    4 5 1 4
    1 2 2 1
    1 3 1 2
    2 3 1 0
    2 4 1 3
    3 4 2 1

  Output:
    3 8
*/

struct MinCostMaxFlow {
    struct Edge {
        int to, rev;
        long long cap, cost;
    };

    int n;
    vector<vector<Edge>> g;
    vector<long long> pot, dist; 
    vector<int> pv_v, pv_e;

    static constexpr long long INF = (long long)4e18;

    explicit MinCostMaxFlow(int n) : n(n), g(n), pot(n, 0), dist(n), pv_v(n), pv_e(n) {}

    void add_edge(int u, int v, long long cap, long long cost) {
        Edge a{v, (int)g[v].size(), cap, cost};
        Edge b{u, (int)g[u].size(), 0,   -cost};
        g[u].push_back(a);
        g[v].push_back(b);
    }

    void init_potentials_spfa(int s) {
        deque<int> dq;
        vector<bool> inq(n, false);
        fill(pot.begin(), pot.end(), INF);
        pot[s] = 0; dq.push_back(s); inq[s] = true;
        while (!dq.empty()) {
            int u = dq.front(); dq.pop_front(); inq[u] = false;
            for (auto &e : g[u]) if (e.cap > 0) {
                if (pot[e.to] > pot[u] + e.cost) {
                    pot[e.to] = pot[u] + e.cost;
                    if (!inq[e.to]) {
                        inq[e.to] = true;
                        if (!dq.empty() && pot[e.to] < pot[dq.front()]) dq.push_front(e.to); else dq.push_back(e.to);
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) if (pot[i] >= INF/2) pot[i] = 0;
    }

    pair<long long,long long> min_cost_max_flow(int s, int t, long long maxf = INF, bool use_spfa_init = true) {
        if (use_spfa_init) init_potentials_spfa(s);
        long long flow = 0, cost = 0;
        while (flow < maxf) {
            priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
            fill(dist.begin(), dist.end(), INF);
            dist[s] = 0; pq.push({0, s});
            while (!pq.empty()) {
                auto [d, u] = pq.top(); pq.pop();
                if (d != dist[u]) continue;
                for (int i = 0; i < (int)g[u].size(); ++i) {
                    auto &e = g[u][i]; if (e.cap <= 0) continue;
                    long long nd = d + e.cost + pot[u] - pot[e.to];
                    if (dist[e.to] > nd) {
                        dist[e.to] = nd;
                        pv_v[e.to] = u; pv_e[e.to] = i;
                        pq.push({nd, e.to});
                    }
                }
            }
            if (dist[t] == INF) break; 

            for (int v = 0; v < n; ++v) if (dist[v] < INF) pot[v] += dist[v];

            long long add = maxf - flow;
            for (int v = t; v != s; v = pv_v[v]) {
                auto &e = g[pv_v[v]][pv_e[v]];
                add = min(add, e.cap);
            }
            for (int v = t; v != s; v = pv_v[v]) {
                auto &e = g[pv_v[v]][pv_e[v]];
                auto &re = g[e.to][e.rev];
                e.cap -= add; re.cap += add;
            }
            flow += add;
            cost += add * pot[t];
        }
        return {flow, cost};
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s, t;
    if (!(cin >> n >> m >> s >> t)) {
        cerr << "Input: n m s t followed by m lines: u v cap cost (1-indexed)\n";
        return 0;
    }
    --s; --t;
    MinCostMaxFlow mcmf(n);
    for (int i = 0; i < m; ++i) {
        int u, v; long long cap, cost; cin >> u >> v >> cap >> cost; --u; --v;
        mcmf.add_edge(u, v, cap, cost);
    }

    auto [flow, cost] = mcmf.min_cost_max_flow(s, t);
    cout << flow << ' ' << cost << '\n';
    return 0;
}
