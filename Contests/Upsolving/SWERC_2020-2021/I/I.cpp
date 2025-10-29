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
    int n, m;
    cin >> n >> m;
    
    vector<vi> g(n, vi());

    FOR (i, 0, m) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    auto bfs = [&](int src) -> pi {
        queue<int> q;
        vector<int> dist(n, -1);
        dist[src] = 0;
        q.push(src);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int &v : g[u]) {
                if (dist[v] != -1)
                    continue;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }

        int mx = -1, imx = -1;

        FOR (i, 0, n) {
            if (dist[i] == -1)
                return {INF, -1};
            if (dist[i] > mx)
                mx = dist[i], imx = i;
        }

        return {mx, imx};
    };

    pi ret = bfs(0);
    if (ret.second == -1) {
        cout << -1 << ENDL;
        return 0;
    }

    int farthest = ret.second;
    int diameter = bfs(farthest).first;

    cout << ceil(log2(diameter)) << ENDL;

    return 0;
}