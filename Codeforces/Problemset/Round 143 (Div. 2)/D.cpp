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
  
  int x, y, z, x1, y1, z1;
  cin >> x >> y >> z;
  cin >> x1 >> y1 >> z1;

  vi a(6);
  for (auto &x : a) cin >> x;

  int ans = 0;

  if (y < 0)  ans += a[0];
  if (y > y1) ans += a[1];
  if (z < 0)  ans += a[2];
  if (z > z1) ans += a[3];
  if (x < 0)  ans += a[4];
  if (x > x1) ans += a[5];

  cout << ans << ENDL;
  
  return 0;
}