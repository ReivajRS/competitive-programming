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

vector<vi> tarjan(vector<vi>& g) {
    int n = SZ(g), timer = 0;
    vector<vi> scc;
    vi tin(n, -1), low(n, 0), vis(n, 0);
    stack<int> st;
    auto dfs = [&](auto self, int u) -> void {
        tin[u] = low[u] = timer++;
        st.push(u);
        vis[u] = 1;
        for (int v : g[u]) {
            if (tin[v] == -1) self(self, v);
            if (vis[v]) low[u] = min(low[u], low[v]);
        }
        if (low[u] == tin[u]) {
            scc.pb({});
            while (1) {
                int v = st.top();
                st.pop();
                vis[v] = 0;
                scc.back().pb(v);
                if (u == v) break;
            }
        }
    };
    FOR (i, 0, n) if (tin[i] == -1) dfs(dfs, i);
    return scc;
}

vector<vi> g, scc;
vector<vector<pi>> gc;
map<pi, int> dist;
vector<bool> vis;
vi comp, dp;

void dfs(int src, int u, int d = 0) {
    if (vis[u])
        return;
    vis[u] = 1;
    dist[{src, u}] = max(dist[{src, u}], d);
    for (auto &v : g[u]) {
        if (comp[u] != comp[v])
            continue;
        dfs(src, v, d + 1);
    }
    vis[u] = 0;
}

int solve(int u) {
    int &ans = dp[u];
    if (ans != -1)
        return ans;
    ans = 0;
    for (auto &v : scc[comp[u]])
        ans = max(ans, dist[{u, v}]);
    for (auto &[a, b] : gc[comp[u]])
        ans = max(ans, solve(b) + dist[{u, a}] + 1);
    return ans;
}

signed main() { __
    int n, m;
    cin >> n >> m;
    
    g.assign(n, vi());
    FOR (i, 0, m) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
    }

    scc = tarjan(g);
    comp.resize(n);
    vis.assign(n, 0);

    FOR (i, 0, SZ(scc))
        for (auto &u : scc[i])
            comp[u] = i;

    FOR (i, 0, SZ(scc))
        for (auto &u : scc[i])
            dfs(u, u);
    
    gc.assign(SZ(scc), vector<pi>());

    FOR (i, 0, n) {
        FOR (j, 0, SZ(g[i])) {
            if (comp[i] == comp[g[i][j]])
                continue;
            gc[comp[i]].pb({i, g[i][j]});
        }
    }

    dp.assign(n, -1);

    FOR (i, 0, n)
        solve(i);

    cout << *max_element(ALL(dp)) + 1 << ENDL;

    return 0;
}