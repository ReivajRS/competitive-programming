#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
using ll = long long;

void dfs(int u, int p, int& time, vector<vector<int>>& g, vector<int>& in, vector<int>& out) {
  in[u] = time++;
  for (int v : g[u])  {
    if (v == p) continue;
    dfs(v, u, time, g, in, out);
  }
  out[u] = time++;
}

void solve() {
  int n;
  cin >> n;
  vector<int> val(n);
  for (int i = 0; i < n; i++) {
    cin >> val[i];
  }
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> in(n), out(n);
  int time = 0;
  dfs(0, -1, time, g, in, out);
  vector<int> pre_mx(2 * n), suf_mx(2 * n);
  for (int i = 0; i < n; i++) {
    pre_mx[in[i]] = val[i];
    suf_mx[out[i]] = val[i];
  }
  for (int i = 1; i < 2 * n; i++) {
    pre_mx[i] = max(pre_mx[i - 1], pre_mx[i]);
  }
  for (int i = 2 * n - 2; i >= 0; i--) {
    suf_mx[i] = max(suf_mx[i + 1], suf_mx[i]);
  }
  pair<int, int> ans = {-1, -1};
  for (int i = 0; i < n; i++) {
    int l = in[i] > 0 ? pre_mx[in[i] - 1] : -1;
    int r = out[i] < 2 * n - 1 ? suf_mx[out[i] + 1] : -1;
    int mx = max(l, r);
    if (mx > val[i]) {
      ans = max(ans, {val[i], i});
    }
  }
  cout << (ans.first == -1 ? 0 : ans.second + 1) << '\n';
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