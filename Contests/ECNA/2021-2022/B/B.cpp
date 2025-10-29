#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) begin(x),end(x)
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i,a,b) for(int i = (int)a - 1; i>= (int)b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

constexpr int INF = 1e8;

signed main() { __
  int n, m;
  cin >> n >> m;

  vi a(n + 1);
  FOR (i, 1, n + 1) {
    cin >> a[i];
  }

  vi out_d(n + 1, 0);
  vi p(n + 1, 0);

  p[0] = -1;

  FOR (i, 0, m) {
    int u, v;
    cin >> u >> v;
    out_d[u] = 1;
    p[v] = u;
  }

  int ans = INF;
  vi min_found(n + 1, INF);
  FOR (u, 1, n + 1) if (!out_d[u]) {
    int to_root = 0, val = a[u], v = p[u];
    
    while (v != -1) {
      to_root += a[v];
      v = p[v];
    }

    v = p[u];
    while (v != -1) {
      to_root -= a[v];
      ans = min(ans, min_found[v] + val + a[v] + to_root);
      min_found[v] = min(min_found[v], val);
      val += a[v];
      v = p[v];
    }
  }
  cout << ans << ENDL;

  return 0;
}