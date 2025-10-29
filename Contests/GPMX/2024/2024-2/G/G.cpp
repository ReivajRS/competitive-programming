#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main() { __
  int n;
  cin >> n;
  
  vector<vi> g(n, vi());
  FOR (i, 0, n - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }

  vi sz(n, 0);
  auto dfs = [&](auto self, int u, int p = -1) -> int {
    sz[u] = 1;
    for (auto &v : g[u]) {
      if (v == p)
        continue;
      sz[u] += self(self, v, u);
    }
    return sz[u];
  };
  dfs(dfs, 0);

  ll mx = 0, cnt = 0;
  auto dfs2 = [&](auto self, int u, int p = -1) -> void {
    for (auto &v : g[u]) {
      if (v == p)
        continue;
      ll val = 1ll * sz[v] * (n - sz[v]);
      if (val > mx) {
        mx = val;
        cnt = 1;
      } else if (val == mx) {
        cnt++;
      }
      self(self, v, u);
    }
  };
  dfs2(dfs2, 0);

  cout << mx << ' ' << cnt << ENDL;

  return 0;
}