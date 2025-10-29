#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

void solve() {
  int n, m, h;
  cin >> n >> m >> h;

  vector<vector<pi>> g(n + 1);
  vector<bool> a(n + 1, 0);

  FOR (i, 0, h) {
    int x;
    cin >> x;
    a[x - 1] = 1;
  }

  FOR (i, 0, m) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    g[u].pb({v, w});
    g[v].pb({u, w});
  }

  const ll INF = 1e15;
  auto dijkstra = [&](int src) -> vector<vector<ll>> {
    vector<vector<ll>> dist(n + 1, vector<ll>(2, INF));
    priority_queue<tuple<ll, bool, int>> pq;
    dist[src][a[src]] = 0;
    pq.push({0, a[src], src});
    while (!pq.empty()) {
      auto [d, awh, u] = pq.top();
      pq.pop();
      d *= -1;
      if (d > dist[u][awh]) continue;
      bool has_horse = awh || a[u];
      for (auto [v, w] : g[u]) {
        if (has_horse) w /= 2;
        if (dist[u][awh] + w > dist[v][has_horse])
          continue;
        dist[v][has_horse] = dist[u][awh] + w;
        pq.push({-dist[v][has_horse], has_horse, v});
      }
    }
    return dist;
  };

  vector<vector<ll>> dist1 = dijkstra(0), dist2 = dijkstra(n - 1);

  ll mn = INF;
  FOR (i, 0, n) {
    ll d1 = min(dist1[i][0], dist1[i][1]);
    ll d2 = min(dist2[i][0], dist2[i][1]);
    mn = min(mn, max(d1, d2));
  }

  if (mn == INF) mn = -1;

  cout << mn << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }

  return 0;
}