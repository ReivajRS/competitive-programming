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

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n, m;
  cin >> n >> m;

  vector<vi> g_out(n);
  vector<vi> g_in(n);

  FOR (i, 0, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g_out[u].pb(v);
    g_in[v].pb(u);
  }

  ll ans = 0;

  FOR (u, 0, n) {
    vector<bool> a(n);
    for (auto x : g_out[u]) a[x] = 1;
    FOR (v, 0, n) if (u != v) {
      ll cnt = 0;
      for (auto x : g_in[v]) cnt += a[x];
      ans += cnt * (cnt - 1) / 2;
    }
  }

  cout << ans << ENDL;
  
  return 0;
}