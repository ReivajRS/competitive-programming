#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) (ll)(x.size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define ROF(i, a, b) for (ll i = (a)-1; i >= (b); --i)
#define ENDL '\n'

constexpr ll INF = 1e14;

vector<vector<pi>> g;
vi dist;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n,m,mn,mx;
    cin >> n >> m >> mn >> mx;
    g.assign(n,vector<pi>());
    FOR(i,0,m){
        ll x,y,w;
        cin >> x >> y >> w;
        g[x].pb({y,w});
        g[y].pb({x,w});
    }
    set<pi> calles;
    dist.assign(n,INF);
    dist[0] = 0;
    priority_queue<pi> q;
    q.push({0,0});
    while(SZ(q)){
        auto [du,u] = q.top();
        du *= -1;
        q.pop();
        for(auto &[v,dv]:g[u]){
            if(2*du < mx){
                calles.insert({min(u,v),max(u,v)});
            }
            if((du+dv)<dist[v] && 2*(du+dv)<= mx){
                dist[v] = du+dv;
                q.push({-dist[v],v});
            }
        }
    }

    cout << SZ(calles) << ENDL;

    return 0;
}