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

int LOG;
vi depth;
vector<vi> g, up;

void dfs(int u, int p = -1) {
    for (auto &v : g[u]) {
        if (v == p)
            continue;
        depth[v] = depth[u] + 1;
        up[v][0] = u;
        for (int i = 1; i < LOG; i++)
            up[v][i] = up[up[v][i - 1]][i - 1];
        dfs(v, u);
    }
}

void build(int root, int n) {
    LOG = ceil(log2(n)) + 1;
    depth.resize(n);
    up.assign(n, vi(LOG));
    depth[root] = 0;
    dfs(root);
}

int lca(int a, int b) {
    if (depth[a] < depth[b])
        swap(a, b);
    
    int dif = depth[a] - depth[b];
    for (int i = LOG - 1; i >= 0; i--) {
        if (dif & (1 << i))
            a = up[a][i];
    }
    
    if (a == b)
        return a;
    
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }

    return up[a][0];
}

signed main() { __
    int n, q;
    cin >> n >> q;

    g.assign(n, vi());

    FOR (i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    build(0, n);

    while (q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        cout << depth[u] + depth[v] - 2 * depth[lca(u, v)] << ENDL;
    }

    return 0;
}