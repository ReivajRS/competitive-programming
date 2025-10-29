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
  int n, m;
  cin >> n >> m;

  vector<vi> g(n, vi());
  vi color(n, -1);

  FOR (i, 0, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }

  auto dfs = [&](auto &dfs, int u) -> bool {
    for (auto &v : g[u]) {
      if (color[v] == -1) {
        color[v] = color[u] ^ 1;
        if (!dfs(dfs, v))
          return false;
      }
      if (color[v] == color[u])
        return false;
    }
    return true;
  };

  color[0] = 0;
  bool is_bipartite = dfs(dfs, 0);

  if (is_bipartite) {
    // Bob
    vector<vi> sets(2, vi());
    FOR (i, 0, n) {
      if (color[i] == 0) {
        sets[0].pb(i);
      } else {
        sets[1].pb(i);
      }
    }
    cout << "Bob" << endl;
    FOR (i, 0, n) {
      int a, b;
      cin >> a >> b;
      if (a > b)
        swap(a, b);
      if (b == 3) {
        int c = a - 1;
        bool flag = sets[c].empty();
        if (flag)
          c ^= 1;
        cout << sets[c].back() + 1 << ' ' << (flag ? 3 : c + 1) << endl;
        sets[c].pop_back();
        continue;
      }
      int c = SZ(sets[0]) >= SZ(sets[1]) ? 0 : 1;
      cout << sets[c].back() + 1 << ' ' << c + 1 << endl;
      sets[c].pop_back();
    }
  } else {
    // Alice
    cout << "Alice" << endl;
    FOR (i, 0, n) {
      cout << 1 << ' ' << 2 << endl;
      int x, y;
      cin >> x >> y;
    }
  }
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