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

struct Point {
  int x, y;
};

ll sq_dist(Point a, Point b) {
  int dx = a.x - b.x, dy = a.y - b.y;
  return 1ll * dx * dx + 1ll * dy * dy;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  Point s1, s2;
  cin >> n >> s1.x >> s1.y >> s2.x >> s2.y;
  vector<Point> v(n);
  for (auto &[x, y] : v) {
    cin >> x >> y;
  }

  ll ans = 1e18;
  FOR (i, 0, n) {
    ll r1 = sq_dist(s1, v[i]);
    ll r2 = 0; 
    FOR (j, 0, n) {
      ll d = sq_dist(s1, v[j]);
      if (d > r1) {
        r2 = max(r2, sq_dist(s2, v[j]));
      }
    }
    ans = min(ans, r1 + r2);
  }
  FOR (i, 0, n) {
    ll r2 = sq_dist(s2, v[i]);
    ll r1 = 0; 
    FOR (j, 0, n) {
      ll d = sq_dist(s2, v[j]);
      if (d > r2) {
        r1 = max(r1, sq_dist(s1, v[j]));
      }
    }
    ans = min(ans, r1 + r2);
  }
  cout << ans << ENDL;

  return 0;
}