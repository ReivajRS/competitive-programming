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
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v), g[v].push_back(u);
  }

  if (n == 3) {
    if (m) {
      cout << "yes\n";
    } else {
      cout << "no\n";
    }
    return 0;
  }

  vector<int> comp(n, -1);
  auto dfs = [&](auto&& dfs, int u) -> void {
    for (int v : g[u]) {
      if (comp[v] == -1) {
        comp[v] = comp[u];
        dfs(dfs, v);
      }
    }
  };
  for (int u = 0, c = 0; u < n; ++u) {
    if (comp[u] == -1) {
      comp[u] = c++;
      dfs(dfs, u);
    }
  }

  if (*max_element(comp.begin(), comp.end()) >= 2) {
    cout << "no\n";
    return 0;
  }
  
  set<pair<int, int>> st;
  for (int i = 0; i < n; ++i) {
    st.emplace(SZ(g[i]), i);
  }

  auto ok = [&](int u) -> bool {
    st.erase({SZ(g[u]), u});
    for (int v : g[u]) {
      st.erase({SZ(g[v]), v});
      st.insert({SZ(g[v]) - 1, v});
    }

    auto [c1, _] = *++st.begin();
    auto [c2, __] = *++st.begin();
    auto [c3, ___] = *(++(++st.begin()));
    auto [c4, ____] = *st.rbegin();

    bool ok = c1 == 1 && c2 == 1 && c3 == 2 && c4 == 2;
    
    for (int v : g[u]) {
      st.erase({SZ(g[v]) - 1, v});
      st.insert({SZ(g[v]), v});
    }
    st.insert({SZ(g[u]), u});
    
    return ok;
  };

  if (*max_element(comp.begin(), comp.end()) == 1) {
    vector<int> rep(2), cnt(2);
    for (int i = 0; i < n; ++i) {
      rep[comp[i]] = i;
      ++cnt[comp[i]];
    }
    if (min(cnt[0], cnt[1]) == 1 && ok(cnt[0] == 1 ? rep[0] : rep[1])) {
      cout << "yes\n";
    } else {
      cout << "no\n";
    }
    return 0;
  }

  auto findArticulationPoints = [&](vector<vector<int>>& g) -> vector<bool> {
    int n = SZ(g), t = 0;
    vector<int> tin(n, -1), low(n, -1);
    vector<bool> art(n);
    auto dfs = [&](auto&& dfs, int u, int p = -1) -> void {
      tin[u] = low[u] = t++;
      int children = 0;
      for (int v : g[u]) if (v != p) {
        if (tin[v] != -1) {
          low[u] = min(low[u], tin[v]);
          continue;
        }
        dfs(dfs, v, u);
        if (low[v] >= tin[u] && p != -1) art[u] = 1;
        low[u] = min(low[u], low[v]);
        children++;
      }
      if (p == -1 && children > 1) art[u] = 1;
    };
    FOR (u, 0, n) if (tin[u] == -1) dfs(dfs, u);
    return art;
  };

  vector<bool> art = findArticulationPoints(g);
  for (int i = 0; i < n; ++i) {
    if (!art[i] && ok(i)) {
      cout << "yes\n";
      return 0;
    }
  }
  cout << "no\n";

  return 0;
}