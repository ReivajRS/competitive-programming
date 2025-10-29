#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

constexpr int MOD = 998244353;

void dfs(int u, vector<vector<int>>& g, vector<bool>& vis, vector<int>& comp) {
  vis[u] = 1;
  comp.push_back(u);
  for (int v : g[u]) {
    if (!vis[v]) {
      dfs(v, g, vis, comp);
    }
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<pair<int, int>> pts(n);
  for (int i = 0; i < n; i++) {
    cin >> pts[i].first >> pts[i].second;
  }

  vector<vector<int>> dist(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dist[i][j] = abs(pts[i].first - pts[j].first) + abs(pts[i].second - pts[j].second);
    }
  }

  vector<vector<int>> g(n);

  vector<int> mn_dist(n, 1e9);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j) {
        mn_dist[i] = min(mn_dist[i], dist[i][j]);
      }
    }
    for (int j = 0; j < n; j++) {
      if (dist[i][j] == mn_dist[i]) {
        g[i].push_back(j);
      }
    }
  }

  int cnt = 0;
  vector<int> color(n, -1);
  vector<int> comp_size;
  
  for (int i = 0; i < n; i++) {
    if (color[i] != -1) {
      continue;
    }
    cnt++;
    vector<bool> vis(n);
    vector<int> comp;
    dfs(i, g, vis, comp);
    bool ok = 1;
    for (auto x : comp) {
      for (auto y : comp) {
        if (x != y && dist[x][y] != mn_dist[i]) {
          ok = 0;
        }
      }
    }
    if (ok) {
      for (auto x : comp) {
        color[x] = cnt;
      }
      comp_size.push_back(SZ(comp));
    }
    else {
      color[i] = cnt;
      comp_size.push_back(1);
    }
  }

  int m = SZ(comp_size);
  vector<vector<ll>> dp(m + 1, vector<ll>(n + 1));
  dp[0][0] = 1;
  
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (j + 1 <= n) {
        dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % MOD;
      }
      if (comp_size[i] > 1 && j + comp_size[i] <= n) {
        dp[i + 1][j + comp_size[i]] = (dp[i + 1][j + comp_size[i]] + dp[i][j]) % MOD;
      }
    }
  }

  vector<ll> fact(n + 1), inv(n + 1), inv_fact(n + 1);
  fact[0] = 1;
  for (int i = 1; i <= n; i++) {
    fact[i] = fact[i - 1] * i % MOD;
  }
  inv[0] = inv[1] = 1;
  for (int i = 2; i <= n; i++) {
    inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
  }
  inv_fact[0] = inv_fact[1] = 1;
  for (int i = 2; i <= n; i++) {
    inv_fact[i] = inv_fact[i - 1] * inv[i] % MOD;
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = (ans + (dp[m][i] * (fact[n] * inv_fact[n - i] % MOD) % MOD)) % MOD;
  }

  cout << ans << '\n';

  return 0;
}