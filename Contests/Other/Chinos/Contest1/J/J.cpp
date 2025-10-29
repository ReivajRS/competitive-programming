#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'

vi dijkstra(vector<vector<pi>> &g, int s) {
  vi d(SZ(g), 1e9);
  priority_queue<pi> pq;
  d[s] = 0;
  pq.push({0, s});
  while (!pq.empty()) {
    auto [w, u] = pq.top();
    pq.pop();
    w = -w;
    if (w > d[u]) continue;
    for (auto &[v, ww] : g[u]) {
      if (max(d[u], ww) < d[v]) {
        d[v] = max(d[u], ww);
        pq.push({-d[v], v});
      }
    }
  }
  return d;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  vector<vector<pi>> g(n);
  vector<array<int, 3>> e(m);
  for (auto &[u, v, w] : e) {
    cin >> u >> v >> w;
    g[--u].pb({--v, w}), g[v].pb({u, w});
  }
  vi ds = dijkstra(g, 0), de = dijkstra(g, n - 1);
  int ans = 2e9;
  for (auto &[u, v, w] : e) {
    int mx = max(ds[u], de[v]);
    if (w >= mx) ans = min(ans, w + mx);
    mx = max(ds[v], de[u]);
    if (w >= mx) ans = min(ans, w + mx);
  }
  cout << ans << ENDL;

  return 0;
}