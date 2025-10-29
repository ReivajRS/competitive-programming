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

int n, r, LOG;
vi depth;
vector<vi> g, up, maxCost;
vector<tuple<int, int, int>> edges;
map<pi, int> cost;

void dfs(int u, int p = -1) {
    for (auto &v : g[u]) {
        if (v == p)
            continue;
        depth[v] = depth[u] + 1;
        up[v][0] = u;
        for (int k = 1; k < LOG; k++) {
            up[v][k] = up[up[v][k - 1]][k - 1];
        }
        maxCost[v][0] = cost[{min(u, v), max(u, v)}];
        for (int k = 1; k < LOG; k++) {
            maxCost[v][k] = max(maxCost[v][k - 1], maxCost[up[v][k - 1]][k - 1]);
        }
        dfs(v, u);
    }
}

void build(int root, int n) {
    LOG = ceil(log2(n)) + 1;
    depth.resize(n);
    up.assign(n, vi(LOG)), maxCost.assign(n, vi(LOG));
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

int getMaxCost(int a, int b) {
    int anc = lca(a, b);
    int k = depth[a] - depth[anc];
    int dist1 = 0;
    for (int i = 0; i < LOG; i++) {
        if (k & (1 << i)){
            dist1 = max(dist1, maxCost[a][i]);
            a = up[a][i];
        }
    }
    k = depth[b] - depth[anc];
    int dist2 = 0;
    for (int i = 0; i < LOG; i++) {
        if (k & (1 << i)) {
            dist2 = max(dist2, maxCost[b][i]);
            b = up[b][i];
        }
    }
    return max(dist1, dist2);
}

struct DSU {
    vi e;
    DSU(int n) : e(n, -1) {}
    int find(int x) { return e[x] < 0 ? x : find(e[x]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b];
        e[b] = a;
        return true;
    }
};

int main() { __
    cin >> n >> r;

    edges.resize(r);

    FOR (i, 0, r) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges[i] = {w, u, v};
        cost[{min(u, v), max(u, v)}] = w;
    }

    sort(ALL(edges));

    DSU dsu(n);
    int taken = 0;
    ll mst_cost = 0;
    g.assign(n, vi());

    for (auto &[w, u, v] : edges) {
        if (!dsu.join(u, v))
            continue;
        mst_cost += w;
        g[u].pb(v);
        g[v].pb(u);
        if (taken == n - 1)
            break;
    }

    build(0, n);

    int q;
    cin >> q;

    while (q--) {
        int u, v, w;
        cin >> u >> v;
        u--, v--;
        w = cost[{min(u, v), max(u, v)}];
        cout << mst_cost - getMaxCost(u, v) + w << ENDL;
    }

    return 0;
}