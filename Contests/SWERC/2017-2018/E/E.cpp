#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) (ll) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define ROF(i, a, b) for (ll i = a-1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

map<string, ll> idxs;
using edge = tuple<ll, ll, ll>;
vector<vector<edge>> g;
vi cost, prest;

void dijkstra(vi& initial) {
    priority_queue<tuple<ll, ll, ll>> pq;
    cost.assign(10005, 2e9), prest.assign(10005, -2e9);
    for (auto &x : initial) {
        pq.push({0, 0, x});
        cost[x] = 0, prest[x] = 0;
    }

    while (!pq.empty()) {
        auto [cu, pu, u] = pq.top();
        pq.pop();

        cu *= -1;

        if (cu > cost[u])
            continue;
        
        for (auto &[v, cv, pv] : g[u]) {
            if (cv + cu < cost[v]) {
                cost[v] = cu + cv;
                prest[v] = pu + pv;
                pq.push({-cost[v], prest[v], v});
                continue;
            }
            if (cv + cu == cost[v] && pv + pu > prest[v]) {
                prest[v] = pv + pu;
                pq.push({-cost[v], prest[v], v});
            }
        }                 
    }
}

signed main() {__
    ll budget, n;
    cin >> budget >> n;

    g.assign(10005, vector<edge>());
    vector<bool> inD(10005, 0);

    FOR (i, 0, n) {
        string s1, s2, ing;
        ll price, prestige;
        cin >> s1 >> s2 >> ing >> price >> prestige;
        if (!idxs.count(s1))
            idxs[s1] = SZ(idxs);
        if (!idxs.count(s2))
            idxs[s2] = SZ(idxs);
        ll u = idxs[s1], v = idxs[s2];
        g[v].pb({u, price, prestige});
        inD[u] = 1;
    }

    vi initial;
    for (auto &[k, v] : idxs)
        if (!inD[v])
            initial.pb(v);

    dijkstra(initial);

    // vector<vi> dp(SZ(idxs) + 1, vi(budget + 1, 0));
    vi cur(budget + 1, 0), prev(budget + 1, 0);

    FOR (i, 1, SZ(idxs) + 1) {
        FOR (j, 0, budget + 1) {
            cur[j] = prev[j];
            if (j >= cost[i - 1])
                cur[j] = max(cur[j], prev[j - cost[i - 1]] + prest[i - 1]);
        }
        prev = cur;
    }

    // cout << dp[SZ(idxs)][budget] << ENDL;

    ll mx = LLONG_MIN, mn = LLONG_MAX;

    FOR (i, 0, budget + 1) {
        if (prev[i] > mx) {
            mn = i;
            mx = prev[i];
            continue;
        }
        if (prev[i] == mx)
            mn = min(mn, i);
    }

    if (mx == LLONG_MIN) {
        cout << 0 << ENDL;
        cout << 0 << ENDL;
    }
    else {
        cout << mx << ENDL;
        cout << mn << ENDL;
    }

    return 0;
}