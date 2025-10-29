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
  
  double s, a, b, c;
  cin >> s;
  cin >> a >> b >> c;

  cout << setprecision(10) << fixed;

  if (a == 0 && b == 0 && c == 0) {
    cout << 0 << ' ' << 0 << ' ' << 0 << ENDL;
    return 0;
  }

  double x = a * s / (a + b + c);
  double y = b * s / (a + b + c);
  double z = c * s / (a + b + c);

  cout << x << ' ' << y << ' ' << z << ENDL;
  
  return 0;
}