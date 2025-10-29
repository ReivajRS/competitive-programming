#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ENDL '\n'

int dfs(int u, int p, vector<vector<int>>& g) {
  int ans = 0;
  for (int v : g[u]) {
    if (v != p) {
      ans += dfs(v, u, g);
    }
  }
  ans += max(0, (int)g[u].size() - 2);
  return ans;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<vector<int>> g(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  cout << dfs(0, -1, g);

  return 0;
}