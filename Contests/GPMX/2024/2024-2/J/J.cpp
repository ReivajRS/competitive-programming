#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main() { __
  int n, m;
  cin >> n >> m;

  bool mat[1001][1001] = {0};

  FOR (i, 0, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    mat[u][v] = mat[v][u] = 1;
  }

  if (n == 1) {
    cout << "NO" << ENDL;
    return 0;
  }

  vi comp(n, -1);
  vector<vi> comps(2, vi());
  comp[0] = 0;
  comps[0].pb(0);

  FOR (i, 1, n) {
    if (!mat[0][i]) {
      comp[i] = 1;
      comps[1].pb(i);
      break;
    }
  }

  vector<pi> edges;

  FOR (i, 0, n) {
    if (comp[i] != -1)
      continue;

    vi v(2, 0);
    FOR (j, 0, n) {
      if (i == j || comp[j] == -1)
        continue;
      if (mat[i][j])
        v[comp[j]]++;
    }

    int mn = SZ(comps[0]) - v[0] <= SZ(comps[1]) - v[1] ? 0 : 1;

    for (auto &x : comps[mn]) {
      if (mat[i][x])
        continue;
      mat[i][x] = mat[x][i] = 1;
      edges.pb({i, x});
    }

    comp[i] = mn;
    comps[mn].pb(i);
  }

  cout << "YES" << ENDL;
  cout << SZ(edges) << ENDL;

  for (auto &[x, y] : edges) {
    cout << x + 1 << ' ' << y + 1 << ENDL;
  }

  return 0;
}