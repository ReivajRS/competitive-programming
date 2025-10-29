#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) (ll) x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i,a,b) for (ll i = (ll)a;i<(ll)b;++i)

signed main() {

  ll n,m;
  cin >> n >> m;
  vector<vector<pi>> g(n);
  FOR(i,0,m){
    ll u,v,w;
    char c;
    cin >> u >> v >> c >> w;
    u--,v--;
    if(c == 'r') w*=-1;
    g[u].pb({v,w});
  }

  vi dist(n,3e8);
  dist[0] = 0;
  
  priority_queue<pi> pq;
  pq.emplace(0,0);
  while(SZ(pq)){
    auto [du,u] = pq.top();
    du*=-1;
    pq.pop();

    if(du>dist[u]) continue;

    for(auto &[v,dv]:g[u]){
      if(du+dv < dist[v]){
        dist[v] = du+dv;
        pq.emplace(-dist[v],v);
      }
    }
  }

  vi ans;
  FOR(i,1,n){
    if(dist[i] < 0){
      ans.pb(i);
    }
  }
  sort(ALL(ans));
  for(auto x:ans) cout << x+1 << '\n';

  return 0;
}