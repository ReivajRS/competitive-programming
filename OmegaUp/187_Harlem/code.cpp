#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())

int precalc(int u, int p, vector<vector<pair<int, int>>>& g, vector<vector<int>>& farthest, vector<multiset<int>>& distances) {
  int mx = 0;
  farthest[u].resize(SZ(g[u]));
  for (int i = 0; i < SZ(g[u]); i++) {
    auto [v, w] = g[u][i];
    if (v == p) {
      continue;
    }
    farthest[u][i] = precalc(v, u, g, farthest, distances) + w;
    distances[u].insert(farthest[u][i]);
    if (SZ(distances[u]) > 2) {
      distances[u].extract(*distances[u].begin());
    }
    mx = max(mx, farthest[u][i]);
  }
  return mx;
}

void dfs(int u, int p, int farthest_from_parent, vector<vector<pair<int, int>>>& g, vector<vector<int>>& farthest, vector<multiset<int>>& distances, vector<int>& ans) {
  distances[u].insert(farthest_from_parent);
  ans[u] = *distances[u].rbegin();
  for (int i = 0; i < SZ(g[u]); i++) {
    auto [v, w] = g[u][i];
    if (v == p) {
      continue;
    }
    int val = farthest[u][i];
    bool contained = distances[u].count(val);
    if (contained) {
      distances[u].extract(val);
    }
    dfs(v, u, *distances[u].rbegin() + w, g, farthest, distances, ans);
    if (contained) {
      distances[u].insert(val);
    }
  }
  distances[u].extract(farthest_from_parent);
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

  vector<vector<int>> farthest(n);
  vector<multiset<int>> distances(n);
  precalc(0, -1, g, farthest, distances);

  vector<int> ans(n);
  dfs(0, -1, 0, g, farthest, distances, ans);

  int idx, mn = 1e9 + 5;
  for (int i = 0; i < n; i++) {
    if (ans[i] < mn) {
      idx = i;
      mn = ans[i];
    }
  }

  cout << idx + 1 << ' ' << mn << '\n';
  
  return 0;
}