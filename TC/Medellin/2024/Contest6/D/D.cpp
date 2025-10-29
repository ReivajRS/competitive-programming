#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'

pair<int, vi> hopcroftKarp(vector<vi>& g, int m) {
  int res = 0;
  vi btoa(m, -1), A(SZ(g)), B(m), cur, next;
  auto dfs = [&](auto self, int a, int L) -> bool {
    if (A[a] != L) return 0;
    A[a] = -1;
    for (int b : g[a]) if (B[b] == L + 1) {
      B[b] = 0;
      if (btoa[b] == -1 || self(self, btoa[b], L + 1)) return btoa[b] = a, 1;
    }
    return 0;
  };
  while (1) {
    fill(ALL(A), 0);
    fill(ALL(B), 0);
    cur.clear();
    for (int a : btoa) if (a != -1) A[a] = -1;
    FOR(a, 0, SZ(g)) if (A[a] == 0) cur.pb(a);
    for (int lay = 1;; lay++) {
      bool islast = 0;
      next.clear();
      for (int a : cur) for (int b : g[a]) {
        if (btoa[b] == -1) {
          B[b] = lay;
          islast = 1;
        }
        else if (btoa[b] != a && !B[b]) {
          B[b] = lay;
          next.pb(btoa[b]);
        }
      }
      if (islast) break;
      if (next.empty()) return {res, btoa};
      for (int a : next) A[a] = lay;
      cur.swap(next);
    }
    FOR (a, 0, SZ(g)) res += dfs(dfs, a, 0);
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n, m;
  cin >> n >> m;

  vector<array<int, 3>> edges(m, array<int, 3>());

  for (auto &[w, u, v] : edges) {
    cin >> u >> v >> w;
    u--, v--;
  }

  sort(ALL(edges));

  auto check = [&](int m) -> bool {
    vector<vi> g(n, vi());
    for (auto &[w, u, v] : edges) {
      if (w > m)
        break;
      g[u].pb(v);
    }
    return hopcroftKarp(g, n).first == n;
  };

  if (!check(1e9 + 1)) {
    cout << -1 << ENDL;
    return 0;
  }

  int l = 1, r = 1e9 + 1;

  while (l < r) {
    int m = (l + r) / 2;
    if (check(m)) {
      r = m;
    }
    else {
      l = m + 1;
    }
  }

  cout << r << ENDL;

  return 0;
}