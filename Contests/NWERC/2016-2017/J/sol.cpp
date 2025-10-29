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

constexpr ll INF = 1e18;

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
    int n, q, s;
    cin >> n >> q >> s;

    // IDs
    // Sensors 0 -> s - 1
    // Queues s -> s + q*n - 1
    // Windows s + q*n -> s + q*n + n - 1
    // Source s + q*n + n
    // Sink s + q*n + n + 1

    Dinic mf(s + q*n + n + 2);
    int S = s + q*n + n, T = S + 1;

    vi links(s), qcaps(q);

    FOR (i, 0, s) {
        int x;
        cin >> x;
        links[i] = x - 1;
    }

    FOR (i, 0, q) {
        int x;
        cin >> x;
        qcaps[i] = x;
    }

    ll generated = 0;

    FOR (i, 0, n) {
        int d, window = s + q*n + i;
        cin >> d;
        FOR (j, 0, s) {
            int x;
            cin >> x;
            generated += x;
            mf.addEdge(j, s + links[j] + i*q, x);
        }
        FOR (j, 0, q)
            mf.addEdge(s + j + i*q, window, qcaps[j]);
        if (i < n - 1)
            FOR (j, 0, q)
                mf.addEdge(window, s + j + (i+1)*q, INF);
        mf.addEdge(window, T, d);
    }

    FOR (i, 0, s)
        mf.addEdge(S, i, INF);

    ll flow = mf.calc(S, T);

    if (flow == generated)
        cout << "possible" << ENDL;
    else
        cout << "impossible" << ENDL;

    return 0;
}