#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())

void dfs(int u, int p, vector<vector<int>> &g, vector<set<int>*> &st, vector<int> &ans) {
  for (auto &v : g[u]) {
    if (v == p) {
      continue;
    }
    dfs(v, u, g, st, ans);
    if (SZ((*st[v])) > SZ((*st[u]))) {
      swap(st[v], st[u]);
    }
    for (auto &x : *st[v]) {
      st[u]->insert(x);
    }
    st[v]->clear();
  }
  ans[u] = SZ((*st[u]));
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<set<int>*> st(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    st[i] = new set<int>;
    st[i]->insert(x);
  }

  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> ans(n);

  dfs(0, -1, g, st, ans);

  for (int i = 0; i < n; i++) {
    cout << ans[i] << ' ';
  }

  cout << '\n';
}