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

const double PI = acos(-1.0);
inline double DEG_TO_RAD(double d) { return (d * PI / 180.0); }

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int theta, n;
  cin >> theta >> n;

  int theta_c = 180 - 90 - theta;
  double ang, ang_c;
  ang = DEG_TO_RAD(theta);
  ang_c = DEG_TO_RAD(theta_c);
  double sin_ang_c = sin(ang_c);
  double sin_ang = sin(ang);
  double div = sin_ang_c / sin_ang;

  vector<tuple<int, int, double>> a(n);
  for (auto &[x, h, sh] : a) {
    cin >> x >> h;
    sh = h * div;
  }

  sort(ALL(a));

  double ans = 0;
  double l = 0;

  FOR (i, 0, n) {
    auto [x, h, sh] = a[i];
    double y = x + sh;
    if (l > y) {
      continue;
    }
    if (l > x) {
      ans += y - l;
    }
    else {
      ans += sh;
    }
    l = y;
  }

  cout << setprecision(10) << fixed;
  cout << ans << ENDL;
  
  return 0;
}