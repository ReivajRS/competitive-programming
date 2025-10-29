#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void get_sz(int u, int p, vector<vector<int>>& g, vector<int>& sz) {
  sz[u] = 1;
  for (int v : g[u]) {
    if (v != p) {
      get_sz(v, u, g, sz);
      sz[u] += sz[v];
    }
  }
}

void dfs(int u, int p, bool is_heavy, vector<vector<int>>& g, vector<int>& sz, vector<vector<int>>& children, vector<int>& c, vector<int>& cnt, int& mx_cnt, vector<ll>& ans) {
  int mx_sz = -1, heavy_child = -1;
  for (int v : g[u]) {
    if (v != p && sz[v] > mx_sz) {
      mx_sz = sz[v];
      heavy_child = v;
    }
  }
  for (int v : g[u]) {
    if (v != p && v != heavy_child) {
      dfs(v, u, 0, g, sz, children, c, cnt, mx_cnt, ans);
    }
  }
  if (heavy_child != -1) {
    dfs(heavy_child, u, 1, g, sz, children, c, cnt, mx_cnt, ans);
    swap(children[u], children[heavy_child]);
    ans[u] = ans[heavy_child];
  }
  children[u].push_back(u);
  cnt[c[u]]++;
  if (cnt[c[u]] > mx_cnt) {
    mx_cnt = cnt[c[u]];
    ans[u] = c[u];
  }
  else if (cnt[c[u]] == mx_cnt) {
    ans[u] += c[u];
  }
  for (int v : g[u]) {
    if (v != p && v != heavy_child) {
      for (int x : children[v]) {
        cnt[c[x]]++;
        if (cnt[c[x]] > mx_cnt) {
          mx_cnt = cnt[c[x]];
          ans[u] = c[x];
        }
        else if (cnt[c[x]] == mx_cnt) {
          ans[u] += c[x];
        }
        children[u].push_back(x);
      }
    }
  }
  if (!is_heavy) {
    for (int v : children[u]) {
      cnt[c[v]]--;
    }
    mx_cnt = 0;
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n;
  cin >> n;

  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }

  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> sz(n);
  get_sz(0, -1, g, sz);

  vector<vector<int>> children(n);
  vector<int> cnt(n + 1);
  vector<ll> ans(n);
  int mx_cnt = 0;

  dfs(0, -1, 0, g, sz, children, c, cnt, mx_cnt, ans);

  for (int i = 0; i < n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
  
  return 0;
}