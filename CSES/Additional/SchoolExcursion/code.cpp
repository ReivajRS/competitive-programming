#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int c, vector<vector<int>>& g, vector<int>& comp) {
  comp[u] = c;
  for (auto v : g[u]) {
    if (comp[v] == -1) {
      dfs(v, c, g, comp);
    }
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int c = 0;
  vector<int> comp(n, -1);

  for (int i = 0; i < n; i++) {
    if (comp[i] == -1) {
      dfs(i, c++, g, comp);
    }
  }

  vector<int> color_cnt(n, 0);
  for (int i = 0; i < n; i++) {
    color_cnt[comp[i]]++;
  }

  vector<int> vals;
  for (int i = 0; i < n; i++) {
    if (color_cnt[i] == 0) {
      break;
    }
    vals.push_back(color_cnt[i]);
  }

  bitset<100001> dp;
  dp[0] = 1;

  for (auto x : vals) {
    dp |= dp << x;
  }

  for (int i = 1; i <= n; i++) {
    cout << dp[i];
  }
  cout << '\n';

  return 0;
}