#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) (int(x.size()))
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

constexpr ll INF = 1e18;
const int MOD1 = 1e9+7,MOD2 = 998244353,MOD3 = 1e9+9;

tuple<vector<ll>,vector<ll>,vector<ll>,vector<ll>> dijkstra(int s, vector<vector<pair<int, int>>>& g) {
  int n = g.size();
  vector<ll> dist(n, INF);
  vector<ll> cnt1(n,0);
  vector<ll> cnt2(n,0);
  vector<ll> cnt3(n,0);
  priority_queue<pair<ll, int>> pq;
  dist[s] = 0;
  cnt1[s] = 1; 
  cnt2[s] = 1; 
  cnt3[s] = 1; 
  pq.emplace(0, s);
  while (!pq.empty()) {
    auto [d, u] = pq.top();
    d = -d;
    pq.pop();
    if (d > dist[u]) {
      continue;
    }
    for (auto [v, w] : g[u]) {
      ll dv = d + w;
      if (dv < dist[v]) {
        cnt1[v] = cnt1[u];
        cnt2[v] = cnt2[u];
        cnt3[v] = cnt3[u];
        dist[v] = dv;
        pq.emplace(-dv, v);
      }else if(dv == dist[v]){
        (cnt1[v] += cnt1[u])%=MOD1;
        (cnt2[v] += cnt2[u])%=MOD2;
        (cnt3[v] += cnt3[u])%=MOD3;
      }
    }
  }
  return {dist,cnt1,cnt2,cnt3};
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m, s, t;
  cin >> n >> m >> s >> t;
  --s, --t;

  vector<vector<pair<int, int>>> g(n), rg(n);
  vector<tuple<int, int, int>> e(m);
  for (auto &[u, v, w] : e) {
    cin >> u >> v >> w;
    --u, --v;
    g[u].emplace_back(v, w);
    rg[v].emplace_back(u, w);
  }

  auto [d1,cnt11,cnt12,cnt13] = dijkstra(s, g);
  auto [d2,cnt21,cnt22,cnt23] = dijkstra(t, rg);
  ll dt = d1[t];
  for (auto [u, v, w] : e) {
    // Es buen camino corto
    if(d1[u]+d2[v] + w == dt){
      bool b1 = ((cnt11[u]*cnt21[v]%MOD1) == cnt11[t]);
      bool b2 = ((cnt12[u]*cnt22[v]%MOD2) == cnt12[t]);
      bool b3 = ((cnt13[u]*cnt23[v]%MOD3) == cnt13[t]);
      if(b1){
        cout << "YES"<<'\n';
      }else{
        if(w > 1) cout << "CAN 1" << '\n';
        else cout << "NO" << '\n';
      }
      
    }else{
      ll need = d1[u]+d2[v]+w - dt + 1;
      if(need<w)
        cout << "CAN " << need << '\n';
      else
        cout << "NO" << '\n';
    }
  }

  return 0;
}