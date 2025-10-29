#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<vector<int>> g(n);
  for (int i = 1; i < n; ++i) {
    int p;
    cin >> p;
    --p;
    g[p].push_back(i);
  }

  string original;
  cin >> original;
  original = " " + original;

  string build = "";
  vector<int> phi;
  auto dfs = [&](auto&& dfs, int u) -> int {
    build += original[u];
    if (phi.empty()) {
      phi.push_back(0);
    } else {
      int g = phi.back();
      while (g && build.back() != build[g]) g = phi[g - 1];
      phi.push_back(g + (build.back() == build[g]));
    }
    int ret = 0;
    if (phi.back()) {
      ret = int(build.size()) - phi.back();
    }
    for (int v : g[u]) {
      ret = max(ret, dfs(dfs, v));
    }
    phi.pop_back();
    build.pop_back();
    return ret;
  };

  int ans = 1;
  for (int v : g[0]) {
    ans = max(ans, dfs(dfs, v));
  }
  cout << ans << '\n';
  return 0;
}