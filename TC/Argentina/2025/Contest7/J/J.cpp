#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = int(1e9) + 7;

struct DSU {
  vector<pair<int, int>> e;
  void addNode() {
    e.emplace_back(-1, 0);
  }
  pair<int, int> get(int u) {
    if (e[u].first == -1) {
      return {u, 0};
    }
    pair<int, int> p = get(e[u].first);
    e[u].first = p.first;
    (e[u].second += p.second) %= MOD;
    return e[u];
  }
  int join(int v, int i, int x) {
    auto [root, depth] = get(v);
    e[root] = {i, (depth + x) % MOD};
    return (depth + x) % MOD;
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  DSU dsu;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    dsu.addNode();
    while (k--) {
      int v, x;
      cin >> v >> x;
      --v;
      ((x %= MOD) += MOD) %= MOD;
      (ans += dsu.join(v, i, x)) %= MOD;
    }
  }
  cout << ans << '\n';

  return 0;
}