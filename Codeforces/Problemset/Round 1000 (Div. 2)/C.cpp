#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)(x).size())

void solve() {
  int n;
  cin >> n;
  vector<int> deg(n);
  vector<unordered_set<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    deg[u]++;
    deg[v]++;
    g[u].insert(v);
    g[v].insert(u);
  }
  int mx = *max_element(deg.begin(), deg.end());
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&](int i, int j) -> bool {
    return deg[i] < deg[j];
  });
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = n - 2; j < n; j++) {
      if (i != p[j]) {
        if (g[i].count(p[j])) {
          ans = max(ans, deg[i] + deg[p[j]] - 2);
        }
        else {
          ans = max(ans, deg[i] + deg[p[j]] - 1);
        }
      }
    }
  }
  cout << ans << '\n';
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