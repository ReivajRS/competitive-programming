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

  int n, k, m;
  cin >> n >> k >> m;

  vector<vector<vi>> g(n, vector<vi>(k + 1));
  vi D(n, -1);
  FOR (i, 0, m) {
    int u, v, d;
    cin >> u >> v >> d;
    --u, --v;
    g[u][d].pb(v),g[v][d].pb(u);
    D[u] = max(D[u], d - 2), D[v] = max(D[v], d - 2);
  }

  vector<vi> dp(n, vi(k + 1));
  FOR (u, 0, n) if (D[u] < 0) dp[u][0] = 1;
  FOR (d, 1, k + 1) {
    FOR (u, 0, n) if (D[u] < d) for (auto &v : g[u][d]) {
      dp[u][d] |= dp[v][d - 1];
    }
  }

  vi ans;
  FOR (u, 0, n) if (dp[u][k]) ans.pb(u + 1);

  cout << SZ(ans) << ENDL;
  for (auto &u : ans) cout << u << ENDL;

  return 0;
}