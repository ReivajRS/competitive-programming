#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;

  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int t = 0;
  vector<int> last(n);
  vector<int> ans(n + 1);

  auto euler = [&](auto &self, int u, int p) -> void {
    if (t - last[a[u]] <= 2) {
      ans[a[u]] = 1;
    }
    for (auto v : g[u]) if (v != p) {
      self(self, v, u);
    }
    last[a[u]] = t++;
  };

  euler(euler, 0, -1);

  for (int i = 1; i <= n; i++) {
    cout << ans[i];
  }
  cout << '\n';
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