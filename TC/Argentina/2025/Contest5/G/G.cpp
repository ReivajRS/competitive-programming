#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) (int(x.size()))

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<vector<int>> g(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v), g[v].push_back(u);
  }

  auto dfs = [&](auto&& dfs, int u, int p = -1, int cats = 0) -> int {
    cats = a[u] ? cats + 1 : 0;
    if (cats > m) {
      return 0;
    }
    int ret = u && g[u].size() == 1;
    for (int v : g[u]) {
      if (v != p) {
        ret += dfs(dfs, v, u, cats);
      }
    }
    return ret;
  };
  cout << dfs(dfs, 0) << '\n';

  return 0;
}