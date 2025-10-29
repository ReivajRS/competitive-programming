#include <bits/stdc++.h>
using namespace std;

int dfs(int u, int p, vector<vector<pair<int, int>>> &g, vector<int> &to_remove) {
  int cnt = 1;
  bool in_branch = false;
  for (auto [v, id] : g[u]) {
    if (v == p) {
      continue;
    }
    int unmatched = dfs(v, u, g, to_remove);
    if (unmatched == -1) {
      return -1;
    }
    if (unmatched == 0) {
      to_remove.push_back(id);
      continue;
    }
    if (in_branch || (unmatched == 2 && cnt == 2)) {
      return -1;
    }
    if (unmatched == 1 && cnt == 1) {
      cnt = 2;
      continue;
    }
    in_branch = true;
  }
  return in_branch ? 0 : cnt;
}

void solve() {
  int n;
  cin >> n;

  vector<vector<pair<int, int>>> g(n);

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back({v, i});
    g[v].push_back({u, i});
  }

  vector<int> to_remove;

  if (dfs(0, -1, g, to_remove) != 0) {
    cout << -1 << '\n';
    return;
  }

  cout << (int)to_remove.size() << '\n';
  for (auto x : to_remove) {
    cout << x + 1 << ' ';
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