#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end();
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(nullptr);

struct Dinic {
    struct Edge {
        int to, rev;
        ll c, oc;
        ll flow() { return max(oc - c, 0LL); }
    };
    vi lvl, ptr, q;
    vector<vector<Edge>> adj;
    Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
    void addEdge(int a, int b, ll c, ll rcap = 0) {
        adj[a].push_back({b, SZ(adj[b]), c, c});
        adj[b].push_back({a, SZ(adj[a]) - 1, rcap, rcap});
    }
    ll dfs(int v, int t, ll f) {
        if (v == t || !f) return f;
        for (int& i = ptr[v]; i < SZ(adj[v]); i++) {
            Edge& e = adj[v][i];
            if (lvl[e.to] == lvl[v] + 1)
                if (ll p = dfs(e.to, t, min(f, e.c))) {
                    e.c -= p, adj[e.to][e.rev].c += p;
                    return p;
                }
        }
        return 0;
    }
    ll calc(int s, int t) {
        ll flow = 0; q[0] = s;
        for(int L = 0; L < 31; L++) do {
            lvl = ptr = vi(SZ(q));
            int qi = 0, qe = lvl[s] = 1;
            while (qi < qe && !lvl[t]) {
                int v = q[qi++];
                for (Edge e : adj[v])
                    if (!lvl[e.to] && e.c >> (30 - L))
                        q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
            }
            while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
        } while (lvl[t]);
        return flow;
    }
    bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

signed main() { __
    int n, m, a, b;

    cin >> n >> m >> a >> b;

    string mat[n];
    FOR (i, 0, n)
        cin >> mat[i];

    Dinic mf(n * m + 2);
    int source = n * m, sink = n * m + 1;

    auto id = [&](int i, int j) -> int {
        return i * m + j;
    };

    FOR (i, 0, n) {
        FOR (j, 0, m) {
            int cellID = id(i, j);
            if (mat[i][j] == '.')
                mf.addEdge(source, cellID, b);
            else
                mf.addEdge(cellID, sink, b);
            if (i > 0)
                mf.addEdge(cellID, id(i - 1, j), a);
            if (j > 0)
                mf.addEdge(cellID, id(i, j - 1), a);
            if (i < n - 1)
                mf.addEdge(cellID, id(i + 1, j), a);
            if (j < m - 1)
                mf.addEdge(cellID, id(i, j + 1), a);
        }
    }

    cout << mf.calc(source, sink) << ENDL;

    return 0;
}