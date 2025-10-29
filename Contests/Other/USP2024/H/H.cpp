#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

constexpr ll INF = 1e18;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m, T;
  cin >> n >> m >> T;

  vector<vector<pair<int, int>>> g(n);
  vector<int> x(m), y(m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v >> x[i] >> y[i];
    --u, --v;
    g[u].emplace_back(v, i);
    g[v].emplace_back(u, i);
  }

  vector<ll> dist(n, INF);
  dist[0] = T;
  priority_queue<pair<ll, int>> pq;
  pq.emplace(-T, 0);
  while (!pq.empty()) {
    auto [t, u] = pq.top();
    pq.pop();
    t = -t;
    if (t > dist[u]) {
      continue;
    }
    for (auto [v, i] : g[u]) {
      ll tt = t, tm = t % (x[i] + y[i]);
      if (tm >= x[i]) {
        tt += x[i] + y[i] - tm;
      }
      if (tt < dist[v]) {
        dist[v] = tt;
        pq.emplace(-tt, v);
      }
    }
  }
  cout << dist[n - 1] << '\n';

  return 0;
}