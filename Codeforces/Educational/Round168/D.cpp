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

void solve() {
  int n;
  cin >> n;

  vi vals(n);
  for (auto &x : vals) {
    cin >> x;
  }
  
  vector<vi> g(n + 1, vi());
  vi parent(n + 1, -1);
  FOR (i, 0, n - 1) {
    int x;
    cin >> x;
    g[x - 1].pb(i + 1);
    parent[i + 1] = x - 1;
  }

  auto dfs = [&](auto &dfs, int u) -> void {
    if (g[u].empty())
      return;
    int mn = 1e9;
    for (auto &v : g[u]) {
      dfs(dfs, v);
      mn = min(mn, vals[v]);
    }
    if (vals[u] < mn) {
      vals[u] = (vals[u] + mn) / 2;
    } else {
      vals[u] = mn;
    }
  };

  int mn = 1e9;
  FOR (i, 0, n) {
    if (parent[i] == 0) {
      dfs(dfs, i);
      mn = min(mn, vals[i]);
    }
  }

  cout << vals[0] + mn << ENDL;
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