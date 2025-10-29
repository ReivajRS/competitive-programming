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

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> edges(m);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    edges[i] = {u - 1, v - 1};
  }

  auto check = [&](int k) -> bool {
    vector<vector<int>> g(n);
    vector<int> vis(n, -1);

    for (int i = 0; i < k; i++) {
      auto [u, v] = edges[i];
      g[u].push_back(v);
    }

    auto dfs = [&](auto& dfs, int u) -> bool {
      vis[u] = 0;
      for (auto v : g[u]) {
        if (vis[v] == 0) {
          return true;
        }
        if (vis[v] == -1) {
          if (dfs(dfs, v)) {
            return true;
          }
        }
      }
      vis[u] = 1;
      return false;
    };

    for (int i = 0; i < n; i++) {
      if (vis[i] == -1 && dfs(dfs, i)) {
        return true;
      }
    }

    return false;
  };

  int l = 1, r = m;
  while (l < r) {
    int mid = (l + r) / 2;
    if (check(mid)) {
      r = mid;
    }
    else {
      l = mid +1;
    }
  }

  cout << (check(l) ? l : -1) << '\n';
  
  return 0;
}