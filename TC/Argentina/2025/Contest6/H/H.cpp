#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) (int(x.size()))
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (int& x : a) {
    cin >> x;
  }

  vector<vector<int>> g(n);
  while (m--) {
    int i, j;
    cin >> i >> j;
    --i, --j;
    g[i].push_back(j), g[j].push_back(i);
  }

  vector<int> ans(n);
  vector<bool> vis(n);
  for (int i = 0; i < n; ++i) {
    if (vis[i]) {
      continue;
    }
    vector<int> ind, vals;
    auto dfs = [&](auto&& dfs, int u) -> void {
      vis[u] = true;
      ind.push_back(u);
      vals.push_back(a[u]);
      for (int v : g[u]) {
        if (!vis[v]) {
          dfs(dfs, v);
        }
      }
    };
    dfs(dfs, i);
    sort(ind.begin(), ind.end());
    sort(vals.rbegin(), vals.rend());
    for (int j = 0; j < ind.size(); ++j) {
      ans[ind[j]] = vals[j];
    }
  }

  for (int x : ans) {
    cout << x << ' ';
  }
  cout << '\n';

  return 0;
}