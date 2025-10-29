#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

using ld = long double;

const ld PI = acos(-1.0L);
constexpr ld EPS = 1e-12;

inline ld RAD_TO_DEG(ld r) {
  return r * 180.0L / PI;
}

struct Point{
  ld x,y;
  Point operator+(Point o) const {
    return {x + o.x, y + o.y};
  }
  Point operator-(Point o) const {
    return {x - o.x, y - o.y};
  }
  Point operator*(ld d) const {
    return {x * d, y * d};
  }
  Point operator/(ld d) const {
    return {x / d, y / d};
  }
  ld dot(Point o) {
    return x * o.x + y * o.y;
  }
  ld sq() {
    return x * x + y * y;
  }
  ld norm() {
    return sqrt(sq());
  }
  ld cross(Point o) {
    return x * o.y - y * o.x;
  }
  ld cross(Point a, Point b) const {
    return (a - *this).cross(b - *this);
  }
  Point perp() {
    return {-y, x};
  }
};

ld angle(Point v, Point w) {
  return acos(clamp(v.dot(w) / v.norm() / w.norm(), -1.0L, 1.0L));
}

ld angle(Point o, Point a, Point b) {
  return angle(a - o, b - o);
}

ld orient(Point a, Point b, Point c) {
  return a.cross(b, c);
}

bool ccw(Point a, Point b, Point c) {
  return orient(a, b, c) > -EPS;
}

ld orientedAngle(Point o, Point a, Point b) {
  if (ccw(o, a, b)) {
    return angle(a - o, b - o);
  }
  else {
    return 2 * PI - angle(a - o, b - o);
  }
}

Point circlePoint(Point c, ld r, ld ang) {
  return Point{c.x + cos(ang) * r, c.y + sin(ang) * r};
}

ld dist(Point a,Point b){
  return hypot(a.x-b.x,a.y-b.y);
}

int sgn(ld x) {
  return (ld(0) < x) - (x < ld(0));
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;

  cout << fixed << setprecision(9);

  while (t--) {
    Point a, b, c;
    ld r;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;
    cin >> r;

    if (dist(a, c) <= r || dist(b, c) <= r) {
      cout << dist(a, b) << '\n';
      continue;
    }
    ld ans = 1e18;
    for (int it = 0; it < 4; ++it) {
      ld lb = PI / 2 * it, rb = PI / 2 * (it + 1);
      for (int i = 0; i < 200; i++) {
        ld m1 = lb + (rb - lb) / 3;
        ld m2 = rb - (rb - lb) / 3;
        Point p1 = circlePoint(c, r, m1);
        Point p2 = circlePoint(c, r, m2);
        ld f1 = dist(a, p1) + dist(b, p1);
        ld f2 = dist(a, p2) + dist(b, p2);
        if (f1 > f2) {
          lb = m1;
        }
        else {
          rb = m2;
        }
      }
      Point p = circlePoint(c, r, lb);
      ans = min(ans, dist(a, p) + dist(b, p));
    }
    cout << ans << '\n';
  }

  return 0;
}