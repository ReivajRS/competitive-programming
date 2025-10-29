#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = a - 1; i >= b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main() { __
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  a--, b--;

  vi w(m);
  vector<vi> ady(n, vi(n, 0)), ne(n, vi(n)), d(n, vi(n, 1e6));
  FOR (i, 0, n) d[i][i] = 0;
  FOR (i, 0, m) {
    int u, v;
    cin >> u >> v >> w[i];  
    u--, v--;
    d[u][v] = d[v][u] = w[i];
    ady[u][v] = ady[v][u] = 1;
    ne[u][v] = ne[v][u] = i;
  }

  FOR (k, 0, n)
    FOR (i, 0, n)
      FOR (j, 0, n)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

  vector<vi> pavimentado(n, vi(n, 0));
  vi active(m, 1);
  auto pavimentar = [&](auto self, int u, int v) -> void {
    if (pavimentado[u][v] || u == v) return;
    pavimentado[u][v] = 1;
    FOR (i, 0, n) {
      if (u == i || d[u][i] + d[i][v] != d[u][v]) continue;
      if (ady[u][i] && w[ne[u][i]] == d[u][i])
        active[ne[u][i]] = 0;
      if (ady[i][v] && w[ne[i][v]] == d[i][v])
        active[ne[i][v]] = 0;
      self(self, u, i);
      self(self, i, u);
      self(self, i, v);
      self(self, v, i);
    }
  };

  pavimentar(pavimentar, a, b);

  int ans = 0;
  FOR (i, 0, m)
    if (active[i])
      ans += w[i];

  cout << ans << ENDL;
  return 0;
}