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
  double cross(const Point &o) const { return x * o.y - y * o.x; }
};

double dist(const Point &p, const Point &o) {
  return sqrt((p.x - o.x) * (p.x - o.x) + (p.y - o.y) * (p.y - o.y));
}

Point middlePoint(const Point &A, const Point &B) {
  return (A + B) / 2;
}

Point circumCenter(const Point &A, const Point &B, const Point &C) {
  Point b = C - A, c = B - A;
  assert(b.cross(c) != 0);
  return A + (b * c.sq() - c * b.sq()).perp() / b.cross(c) / 2;
}

bool is_inside(const Point &p, const Point &c, double r) {
  return dist(p, c) <= r;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

pair<Point, double> welzl(vector<Point> &pts, vector<Point> R, int n) {
  int sz = (int)R.size();
  if (n == 0 || sz == 3) {
    if (sz == 0) {
      return {{0, 0}, 0};
    }
    if (sz == 1) {
      return {R[0], 0};
    }
    if (sz == 2) {
      Point c = middlePoint(R[0], R[1]);
      return {c, dist(c, R[0])};
    }
    Point c = circumCenter(R[0], R[1], R[2]);
    return {c, dist(c, R[0])};
  }
  int rn = uniform_int_distribution<int>(0, n - 1)(rng);
  Point p = pts[rn];
  swap(pts[rn], pts[n - 1]);
  pair<Point, double> C = welzl(pts, R, n - 1);
  if (is_inside(p, C.first, C.second)) {
    return C;
  }
  R.push_back(p);
  return welzl(pts, R, n - 1);
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

  shuffle(pts.begin(), pts.end(), rng);

  auto [c, r] = welzl(pts, {}, n * m);
  
  cout << setprecision(10) << fixed;
  cout << r << ' ' << c.x << ' ' << c.y << '\n';

  return 0;
}