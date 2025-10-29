#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)(x).size())

void dfs(int u, int p, vector<vector<int>>& g, vector<map<int, int>>& mp, vector<vector<pair<int, int>>>& queries, vector<int>& ans) {
  for (auto &v : g[u]) {
    if (v == p) {
      continue;
    }
    dfs(v, u, g, mp, queries, ans);
    if (SZ(mp[u]) < SZ(mp[v])) {
      swap(mp[u], mp[v]);
    }
    for (auto &[k, val] : mp[v]) {
      mp[u][k] += val;
    }
    mp[v].clear();
  }
  for (auto &[k, i] : queries[u]) {
    ans[i] = mp[u][k];
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n, q;
  cin >> n >> q;

  vector<map<int, int>> mp(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    mp[i][x] = 1;
  }

  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> ans(q);
  vector<vector<pair<int, int>>> queries(n);
  for (int i = 0; i < q; i++) {
    int x, k;
    cin >> x >> k;
    x--;
    queries[x].push_back({k, i});
  }

  dfs(0, -1, g, mp, queries, ans);

  for (int i = 0; i < q; i++) {
    cout << ans[i] << '\n';
  }

  return 0;
}