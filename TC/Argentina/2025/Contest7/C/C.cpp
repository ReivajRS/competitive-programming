#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) (int(x.size()))
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> g(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v), g[v].push_back(u);
  }

  int t = 0;
  ll maxOut = 0;
  vector<int> tin(n, -1), sz(n);
  auto dfs = [&](auto&& dfs, int u, int p) -> int {
    int low = tin[u] = t++;
    sz[u] = 1;
    for (int v : g[u]) {
      if (v == p) {
        continue;
      }
      if (tin[v] != -1) {
        low = min(low, tin[v]);
        continue;
      }
      int lv = dfs(dfs, v, u);
      sz[u] += sz[v];
      if (lv == tin[v]) {
        maxOut = max(maxOut, sz[v] * ll(n - sz[v]));
      } else {
        low = min(low, lv);
      }
    }
    return low;
  };
  dfs(dfs, 0, -1);

  ll ans = ll(n) * (n - 1) / 2 - maxOut;
  cout << ans << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}