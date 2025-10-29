#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())

void precalc(int u, int p, vector<vector<pair<int, int>>>& g, vector<pair<int, int>>& owner, vector<int>& cnt) {
  if (SZ(g[u]) == 1) {
    owner[u] = {0, u};
  }
  for (auto [v, w] : g[u]) {
    if (v == p) {
      continue;
    }
    precalc(v, u, g, owner, cnt);
    owner[u] = min(owner[u], {owner[v].first + w, owner[v].second});
  }
  cnt[owner[u].second]++;
}

void dfs(int u, int p, pair<int, int> from_parent, vector<vector<pair<int, int>>>& g, vector<pair<int, int>>& owner, vector<int>& cnt, vector<map<int, int>>& ans) {
  pair<int, int> aux = owner[u];
  cnt[aux.second]--;
  owner[u] = min(owner[u], from_parent);
  cnt[owner[u].second]++;
  
  for (auto &[s, x] : ans[u]) {
    x = cnt[s];
  }

  pair<int, int> second_best = from_parent;
  for (auto [v, w] : g[u]) {
    if (owner[v].second == owner[u].second) {
      continue;
    }
    second_best = min(second_best, {owner[v].first + w, owner[v].second});
  }
  
  for (auto [v, w] : g[u]) {
    if (v == p) {
      continue;
    }
    pair<int, int> owner_u = owner[u];
    bool to_owner = owner[u].second == owner[v].second;
    cnt[owner_u.second]--;
    owner[u] = to_owner ? second_best : owner[u];
    cnt[owner[u].second]++;
    dfs(v, u, {owner[u].first + w, owner[u].second}, g, owner, cnt, ans);
    cnt[owner[u].second]--;
    owner[u] = owner_u;
    cnt[owner_u.second]++;
  }
  
  cnt[owner[u].second]--;
  owner[u] = aux;
  cnt[aux.second]++;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }

  int q;
  cin >> q;

  vector<pair<int, int>> queries(q);
  vector<map<int, int>> ans(n);
  for (int i = 0; i < q; i++) {
    int s, t;
    cin >> s >> t;
    s--, t--;
    queries[i] = {s, t};
    ans[t][s] = -1;
  }

  vector<pair<int, int>> owner(n, {1e9 + 5, -1});
  vector<int> cnt(n);

  precalc(0, -1, g, owner, cnt);
  dfs(0, -1, {1e9 + 5, -1}, g, owner, cnt, ans);

  for (auto [s, t] : queries) {
    cout << ans[t][s] << '\n';
  }

  return 0;
}