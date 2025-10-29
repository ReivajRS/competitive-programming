#include <bits/stdc++.h>
using namespace std;

struct Point {
  double x, y;
  Point() { x = 0, y = 0; }
  Point(double _x, double _y) { x = _x, y = _y; }
  Point operator+(const Point &o) const { return Point(x + o.x, y + o.y); }
  Point operator-(const Point &o) const { return Point(x - o.x, y - o.y); }
  Point operator*(double v) const { return Point(x * v, y * v); }
  Point operator/(double v) const { return Point(x / v, y / v); }
  Point perp() const { return Point(-y, x); }
  double sq() const { return x * x + y * y; }
  double norm() const { return sqrt(sq()); }
  double cross(const Point &o) const { return x * o.y - y * o.x; }
};

Point circumCenter(const Point &A, const Point &B, const Point &C) {
  Point b = C - A, c = B - A;
  assert(b.cross(c) != 0);
  return A + (b * c.sq() - c * b.sq()).perp() / b.cross(c) / 2;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

pair<Point, double> mec(vector<Point> pts) {
  shuffle(pts.begin(), pts.end(), rng);
  Point o = pts[0];
  double r = 0, EPS = 1 + 1e-8;
  for (int i = 0; i < (int)pts.size(); i++) if ((o - pts[i]).norm() > r * EPS) {
    o = pts[i], r = 0;
    for (int j = 0; j < i; j++) if ((o - pts[j]).norm() > r * EPS) {
      o = (pts[i] + pts[j]) / 2;
      r = (o - pts[i]).norm();
      for (int k = 0; k < j; k++) if ((o - pts[k]).norm() > r * EPS) {
        o = circumCenter(pts[i], pts[j], pts[k]);
        r = (o - pts[i]).norm();
      }
    }
  }
  return {o, r};
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  
  vector<Point> new_pts(n);
  for (auto &p : new_pts) {
    cin >> p.x >> p.y;
  }

  int m;
  cin >> m;
  vector<Point> ori_pts(m);
  for (auto &p : ori_pts) {
    cin >> p.x >> p.y;
  }

  vector<Point> pts(n * m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      pts[i * m + j] = ori_pts[j] - new_pts[i];
    }
  }

  auto [c, r] = mec(pts);
  
  cout << setprecision(10) << fixed;
  cout << r << ' ' << c.x << ' ' << c.y << '\n';

  return 0;
}