#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using ld = long double;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

struct Raton {
  int x, y, vx, vy;
};

constexpr ld EPS = 1e-6;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<Raton> a(n);
  FOR(i, 0, n) { cin >> a[i].x >> a[i].y >> a[i].vx >> a[i].vy; }

  auto f = [&](ld t) -> ld {
    ld mnx = 1e9, mxx = -1e9, mny = 1e9, mxy = -1e9;
    for (auto r : a) {
      ld x = ld(r.x) + t * ld(r.vx);
      ld y = ld(r.y) + t * ld(r.vy);
      mnx = min(mnx, x);
      mxx = max(mxx, x);
      mny = min(mny, y);
      mxy = max(mxy, y);
    }

    return max(mxx - mnx, mxy - mny);
  };

  ld l = 0, r = 1e15;
  FOR(i,0,1000) {
    ld m1 = l + (r - l) / 3;
    ld m2 = r - (r - l) / 3;
    ld f1 = f(m1);
    ld f2 = f(m2);
    if (f1 > f2)  // Minimo de f(x)
      l = m1;
    else
      r = m2;
  }
  cout << setprecision(3) << fixed;
  cout << f(l) << ENDL;

  return 0;
}