#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  ll pl, hl, ps, hs, e, g, h;
  cin >> pl >> hl >> ps >> hs >> e >> g >> h;

  tuple<ll, ll, ll> ans = {1e9, 1e9, 1e9};

  for (int i = 0; i <= h; i++) {
    for (int j = 0; j <= h; j++) {
      ll hojas1 = hl * i;
      ll hojas2 = hs * j;
      if (hojas1 + hojas2 < h) {
        continue;
      }
      ll costo1 = pl * i;
      ll costo2 = ps * j;
      ll extra = (costo1 + costo2) < g ? e : 0;
      ans = min(ans, {costo1 + costo2 + extra, i, j});
    }
  }

  auto [x, y, z] = ans;

  cout << x << ' ' << y << ' ' << z << '\n';
  
  return 0;
}