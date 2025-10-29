#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i,a,b) for(int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

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

  auto dfs = [&](auto &dfs, int u, int p = -1) -> int {
    if (p != -1 && SZ(g[u]) == 1) {
      return 1;
    }
    int val = 0;
    for (auto &v : g[u]) if (v != p) {
      val += dfs(dfs, v, u);  
    }
    if (val == 0) {
      val = 1;
    }
    else {
      val -= (val > 0);
    }
    return val;
  };

  cout << (dfs(dfs, 0) ? "Alice" : "Bob") << ENDL;

  return 0;
}