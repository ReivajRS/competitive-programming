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

signed main() { __
  int n, D, a1, a2;
  cin >> n >> D >> a1 >> a2;

  vector<map<int, pi>> g(n);

  FOR (i, 0, n) {
    int m;
    cin >> m;
    while (m--) {
      int d, t, a;
      cin >> d >> t >> a;
      g[i][d - 1] = {t, a};
    }
  }

  auto dijkstra = [&](int src, tuple<int, int, int> initial_state = {-1, -1, -1}) -> vector<vi> {
    priority_queue<tuple<int, int, int>> pq;
    vector<vi> dist(n, vi(360, 1e9));

    if (get<2>(initial_state) == -1) {
      FOR (i, 0, 360) {
        pq.push({0, src, i});
      }
    } else {
      pq.push(initial_state);
    }

    while (!pq.empty()) {
      auto [d, u, a] = pq.top();
      pq.pop();
      d *= -1;

      if (d > dist[u][a])
        continue;
      
      for (auto x : g[u]) {
        int v = x.first;
        auto [t, a_out] = x.second;

        int amx = (a + a1) % 360, amn = (a - a2 + 360) % 360;
        if (!((a_out - amn + 360) % 360 <= (amx - amn + 360) % 360))
          continue;

        int a_in = (g[v][u].second + 180) % 360;
        
        if (d + t >= dist[v][a_in])
          continue;
                
        dist[v][a_in] = d + t;
        pq.push({-dist[v][a_in], v, a_in});
      }
    }

    return dist;
  };

  vector<vi> dist = dijkstra(0);
  vector<tuple<int, int, int>> ways;

  FOR (i, 0, 360) {
    if (dist[D - 1][i] < 1e9) {
      ways.pb({-dist[D - 1][i], D - 1, i});
    }
  }

  int ans = 1e9;

  for (auto &w : ways) {
    vector<vi> dist2 = dijkstra(D - 1, w);
    FOR (i, 0, 360) {
      if (dist2[0][i] < 1e9) {
        ans = min(ans, dist2[0][i]);
      }
    }
  }

  if (ans < 1e9) {
    cout << ans << ENDL;
  } else {
    cout << "impossible" << ENDL;
  }

  return 0;
}