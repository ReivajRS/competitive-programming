#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

constexpr int maxn = 1e5 + 1;
vi g[maxn], comp[maxn];
int c[maxn], is_neighbor[maxn];
bool vis[maxn];
int n, m, cnt;
pi ans = {0, -maxn};

void dfs1(int u) {
  vis[u] = 1;
  comp[c[u]].pb(u);
  for (auto v : g[u]) if (!vis[v] && c[u] == c[v]) {
    dfs1(v);
  }
}

void dfs2(int u) {
  vis[u] = 1;
  for (auto v : g[u]) {
    if (c[u] != c[v]) {
      cnt += (is_neighbor[c[v]] != c[u]);
      is_neighbor[c[v]] = c[u];
      continue;
    }
    if (!vis[v]) {
      dfs2(v);
    }
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> m;

  FOR (i, 0, n) {
    cin >> c[i];
  }

  FOR (i, 0, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }

  FOR (u, 0, n) {
    if (!vis[u]) {
      dfs1(u);
    }
  }

  memset(vis, 0, sizeof vis);

  FOR (i, 0, maxn) {
    if (comp[i].empty()) {
      continue;
    }
    cnt = 0;
    for (auto u : comp[i]) if (!vis[u]) {
      dfs2(u);
    }
    ans = max(ans, {cnt, -i});
  }

  cout << -ans.second << ENDL;
  
  return 0;
}