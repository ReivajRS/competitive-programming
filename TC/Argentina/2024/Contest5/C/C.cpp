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

constexpr ll MOD = 1e9 + 7;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  vector<vector<char>> a(n, vector<char>(m));
  FOR (i, 0, n) FOR (j, 0, m) cin >> a[i][j];

  if (n == 1 && m == 1) {
    cout << (a[0][0] != 'R') << ENDL;
    return 0;
  }

  vector<vector<ll>> h(n + 5, vector<ll>(m + 5, 0LL)), v(n + 5, vector<ll>(m + 5, 0LL));
  vector<ll> pv(m, 0);
  vector<ll> ptrv(m, n - 1);
  if (a[n - 1][m - 1] != 'R') {
    h[n - 1][m - 1] = v[n - 1][m - 1] = 1;
    pv[m - 1] = 1;
  }
  ROF (i, n, 0) {
    ll ph = 0, ptrh = m - 1;
    if (i == n - 1 && a[n - 1][m - 1] != 'R') ph = 1;
    ROF (j, m - (i == n - 1), 0) {
      v[i][j] = pv[j], h[i][j] = ph;
      // actualizar prefixes verticales y horizontales
      // cout << i << ' ' << j << ' ' << v[i][j] << ' ' << h[i][j] << ENDL;
      ph = (ph + v[i][j]) % MOD;
      pv[j] = (pv[j] + h[i][j]) % MOD;
      if (a[i][j] == 'R') {
        ph = (ph - v[i][ptrh--] + MOD) % MOD;
        pv[j] = (pv[j] - h[ptrv[j]--][j] + MOD) % MOD;
      }
    }
  }
  ll ans = (h[0][0] + v[0][0]) % MOD;
  cout << ans << ENDL;

  return 0;
}