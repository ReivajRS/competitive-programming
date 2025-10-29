#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define SZ(x) ((int)x.size())

struct Point {
  ld x, y;
  ld cross(Point& p) const {
    return x * p.y - y * p.x;
  }
};

ld c[2501][2501];

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, k;
  cin >> n >> k;

  vector<Point> pts(n);
  for (auto &[x, y] : pts) {
    cin >> x >> y;
  }
  
  for (int i = 0; i < 2501; i++) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; j++) {
      c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
  }
  
  ld areaP = 0;
  for (int i = 0; i < n; i++) {
    areaP += pts[i].cross(pts[(i + 1) % n]);
  }
  areaP = abs(areaP) / 2;
  
  ld sum = areaP * c[n][k];
  
  for (int i = 0; i < n; i++) {
    ld currentCross = 0;
    currentCross += pts[i].cross(pts[(i + 1) % n]);
    currentCross += pts[(i + 1) % n].cross(pts[(i + 2) % n]);
    for (int j = 2;  j < n - 1; j++) {
      int between = j - 1;
      ld wasted = areaP - abs(currentCross + pts[(i + j) % n].cross(pts[i])) / 2;
      sum -= wasted * c[between][k - 2];
      currentCross += pts[(i + j) % n].cross(pts[(i + j + 1) % n]);
    }
  }
  
  cout << setprecision(10) << fixed;
  cout << sum / c[n][k] << '\n';
  
  return 0;
}