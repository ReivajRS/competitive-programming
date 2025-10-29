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

void solve() {
  int n, k;
  cin >> n >> k;

  vector<vi> g(n, vi());

  FOR (i, 0, n - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }

  vi sz;

  int l = 0, r = n, m = 0, cuts = 0;

  auto dfs = [&](auto self, int u, int p = -1) -> int {
    sz[u] = 1;
    for (auto &v : g[u]) {
      if (v == p)
        continue;
      sz[u] += self(self, v, u);
    }
    if (cuts < k && sz[u] >= m && p != -1) {
      cuts++;
      return 0;
    }
    return sz[u];
  };

  while (r - l > 1) {
    m = (l + r) / 2;
    cuts = 0;
    sz.assign(n, 0);

    dfs(dfs, 0);

    if (cuts >= k && sz[0] >= m) {
      l = m;
    }
    else {
      r = m;
    }
  }

  cout << l << ENDL;
}

signed main() { __
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}