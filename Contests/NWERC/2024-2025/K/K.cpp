#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using ld = long double;
using vi = vector<i64>;

#define SZ(x) ((i64)x.size())
#define FOR(i,a,b) for(i64 i = (i64)a; i < (i64)b; i++)

const i64 INF = 1e15;
i64 n;
vector<vector<pair<i64,i64>>> g;

vi dijkstra(i64 a){
  vi dist(n,INF);
  dist[a] = 0;
  priority_queue<pair<i64,i64>> q;
  q.push({0,a});
  while(SZ(q)){
    auto [du,u] = q.top();
    q.pop();
    du*=-1;
    if (du > dist[u]) {
      continue;
    }
    for(auto &[v,dv]:g[u]){
      if(dist[v] <= dist[u]+dv) continue;
      dist[v] = dist[u]+dv;
      q.push({-dist[v],v});
    }
  }
  return dist;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  i64 m,k;
  cin >> n >> m >> k;
  g.assign(n,vector<pair<i64, i64>>());
  FOR(i,0,m){
    i64 u,v, w;
    cin >> u >> v >> w;
    u--,v--;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  vi distA = dijkstra(0);
  vi distB = dijkstra(n-1);

  vector<pair<i64,ld>> prob(k);
  bool bien = false;
  FOR(i,0,k){
    i64 ii;
    ld p;
    cin >> ii >> p;
    if (p >= 0.9999999 && p <= 1.0000001) {
      bien = true;
    }
    ii--;
    prob[i] = {distA[ii]+distB[ii],p};
  }
  if (!bien) {
    cout << "impossible\n";
    return 0;
  }
  sort(prob.begin(),prob.end());
  ld ev = 0, pa = 0;
  for (auto &[l, p] : prob) {
    ev += (1.0 - pa) * p * l;
    // P(x or y) = P(x) + P(y) - P(x and y)
    pa = pa + p - pa * p;
    if (p >= 0.9999999 && p <= 1.0000001) {
      break;
    }
  }
  cout << setprecision(25) << fixed << ev << '\n';

  return 0;
}