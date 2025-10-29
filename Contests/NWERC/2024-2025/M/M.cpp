#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
using ll = long long;
using i128 = __int128_t;

struct Point {
  i128 x, y;
  Point() { x = 0, y = 0; }
  Point(i128 _x, i128 _y) { x = _x, y = _y; }
  Point operator+(Point o) const { return {x + o.x, y + o.y}; }
  Point operator-(Point o) const { return {x - o.x, y - o.y}; }
  Point operator*(i128 v) const { return {x * v, y * v}; }
  i128 cross(Point o) { return x * o.y - o.x * y; }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<Point> pts(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    pts[i].x = (i128)x, pts[i].y = (i128)y;
  }

  vector<Point> prefix(n + 1);
  for (int i = 0; i < n; i++) {
    prefix[i + 1] = prefix[i] + pts[i];
  }

  i128 sum_areas = 0;

  for (int i = 0; i < n; i++) {
    Point p1 = pts[i] * i;
    p1 = p1 - (prefix[i] - prefix[0]);
    Point p2 = pts[i] * (n - i - 1);
    p2 = (prefix[n] - prefix[i + 1]) - p2;
    sum_areas += p1.cross(p2);
  }

  i128 total_area = 0;
  for (int i = 0; i < n; i++) {
    total_area += pts[i].cross(pts[(i + 1) % n]);
  }

  cout << setprecision(10) << fixed;
  cout << (double)(sum_areas) / (double)(total_area) << '\n';

  return 0;
}