#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

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

  vector<int> comp(n, -1);

  auto dfs = [&](auto &dfs, int u, int cnt) -> void {
    comp[u] = cnt;
    for (auto &v : g[u]) {
      if (comp[v] == -1) {
        dfs(dfs, v, cnt);
      }
    }
  };

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (comp[i] == -1) {
      dfs(dfs, i, cnt);
      cnt++;
    }
  }

  vector<int> sz(cnt);
  vector<vector<int>> nodes(cnt);
  for (int i = 0; i < n; i++) {
    sz[comp[i]]++;
    nodes[comp[i]].push_back(i);
  }

  vector<int> edges(cnt);
  for (int c = 0; c < cnt; c++) {
    set<pair<int, int>> st;
    for (auto &u : nodes[c]) {
      for (auto &v : g[u]) {
        st.insert({min(u, v), max(u, v)});
      }
    }
    edges[c] = SZ(st);
  }

  ll ans = 0;

  for (int i = 0; i < cnt; i++) {
    ans += (ll(sz[i]) * ll(sz[i] - 1)) / 2 - edges[i];
  }

  cout << ans << '\n';

  return 0;
}