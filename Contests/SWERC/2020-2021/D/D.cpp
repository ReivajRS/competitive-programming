#include <bits/stdc++.h>
using namespace std;

#define ENDL '\n'
#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a-1; i >= b; --i)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;

int main() {_
    int n, m, mn, mx;
    cin >> n >> m >> mn >> mx;

    vector<vector<pi>> g(n, vector<pi>());

    FOR (i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }

    auto dijkstra = [&](int src) {
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        vi dist(n, INF);
        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u])
                continue;

            for (auto &[v, w] : g[u]) {
                if (d + w >= dist[v])
                    continue;
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }

        return dist;
    };

    vi dist = dijkstra(0);

    set<pi> vis;

    FOR (i, 0, n) {
        if (dist[i]*2 >= mx)
            continue;
        for (auto &[v, w] : g[i])
            vis.insert({min(i, v), max(i, v)});
    }

    cout << SZ(vis) << ENDL;

    return 0;
}