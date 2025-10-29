#include <bits/stdc++.h>
using namespace std;

#define ENDL '\n'
#define pb push_back
#define SZ(x) (ll) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define ROF(i, a, b) for (ll i = a-1; i >= b; --i)
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e9;
constexpr ll LLINF = 1e18;

ll a, b, e, p;
vector<vi> g, gi;
vi pre, suc;

ll cnt;
vi vis;
void dfs(ll x, ll op){
    if(vis[x]) return;
    vis[x] = true;
    cnt++;
    for(auto y : op == 1 ? gi[x] : g[x])
        dfs(y, op);
}

signed main() {_
    cin >> a >> b >> e >> p;

    g.assign(e, vi()), gi.assign(e, vi());
    pre.resize(e), suc.resize(e);
    
    FOR (i, 0, p) {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        gi[v].push_back(u);
    }

    FOR(i,0,e){
        cnt = 0;
        vis.assign(e,0);
        dfs(i,1);
        pre[i] = cnt-1;
    }

    FOR(i,0,e){
        cnt = 0;
        vis.assign(e,0);
        dfs(i,0);
        suc[i] = cnt-1;
    }

    ll ans = 0;
    FOR (i, 0, e) {
        if (e - a <= suc[i])
            ans++;
    }
    cout << ans << ENDL;

    ans = 0;
    FOR (i, 0, e) {
        if (e - b <= suc[i])
            ans++;
    }
    cout << ans << ENDL;

    ans = 0;
    FOR (i, 0, e) {
        if (b <= pre[i])
            ans++;
    }
    cout << ans << ENDL;


    return 0;
}