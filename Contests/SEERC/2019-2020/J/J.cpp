#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i,a,b) for(int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<vi> g(n);
  int m = n *(n - 1) / 2;
  FOR (i, 0, m) {
    int u, v, w;
    cin >> u >> v >> w;
    g[--u].pb(w), g[--v].pb(w);
  }

  FOR (i, 0, n) sort(ALL(g[i]));

  ll ans = 0;
  FOR (i, 0, n) {
    for (int j = 1; j < n; j += 2) {
      ans += g[i][j];
    }
  }
  cout << ans << ENDL;

  return 0;
}