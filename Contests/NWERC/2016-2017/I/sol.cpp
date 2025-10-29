#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main() { __
    int n, m, k;
    cin >> n >> m >> k;
    vector<bool> iron(n, 0), coal(n, 0);
    FOR (i, 0, m) {
        int x;
        cin >> x;
        iron[x - 1] = 1;
    }
    FOR (i, 0, k) {
        int x;
        cin >> x;
        coal[x - 1] = 1;
    }
    vector<vi> g(n + 2, vi()), rg(n + 2, vi());
    FOR (i, 0, n) {
        int a;
        cin >> a;
        while (a--) {
            int b;
            cin >> b;
            b--;
            g[i].pb(b);
            rg[b].pb(i);
        }
        if (iron[i])
            rg[n].pb(i);
        if (coal[i])
            rg[n + 1].pb(i);
    }

    const int INF = 1e9;
    vector<vi> dist(n + 2, vi(3, INF));

    auto bfs = [&](int src, int id) -> void {
        queue<int> q;
        dist[src][id] = 0 - (id > 0);
        q.push(src);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto &v : (!id ? g[u] : rg[u])) {
                if (dist[v][id] != INF)
                    continue;
                dist[v][id] = dist[u][id] + 1;
                q.push(v);
            }
        }
    };

    bfs(0, 0);
    bfs(n, 1);
    bfs(n + 1, 2);

    int mn = INF;

    FOR (i, 0, n) {
        if (dist[i][0] == INF || dist[i][1] == INF || dist[i][2] == INF)
            continue;
        int d = dist[i][0] + dist[i][1] + dist[i][2];
        mn = min(mn, d);
    }

    if (mn == INF) {
        cout << "impossible" << ENDL;
        return 0;
    }

    cout << mn << ENDL;

    return 0;
}