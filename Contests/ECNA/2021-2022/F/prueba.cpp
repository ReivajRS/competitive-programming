#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const double EPS = 1e-9, PI = acos(-1.0);

typedef double T;

int sgn(T x) { return (T(0) < x) - (x < T(0)); }

struct Point {
  T x, y;

  Point operator+(Point p) const { return {x + p.x, y + p.y}; }
  Point operator-(Point p) const { return {x - p.x, y - p.y}; }
  Point operator*(T d) const { return {x * d, y * d}; }
  Point operator/(T d) const { return {x / d, y / d}; }
  
  T sq() { return x * x + y * y; }
  Point perp() { return {-y, x}; }
};

double dist(Point p1, Point p2) { return hypot(p1.x - p2.x, p1.y - p2.y); }

int circleCircle(Point o1, double r1, Point o2, double r2, pair<Point, Point> &out) {
  Point d = o2 - o1;
  double d2 = d.sq();
  if (d2 == 0) {
    assert(r1 != r2);
    return 0;
  }
  double pd = (d2 + r1 * r1 - r2 * r2) / 2;
  double h2 = r1 * r1 - pd * pd / d2;
  if (h2 >= 0) {
    Point p = o1 + d * pd / d2, h = d.perp() * sqrt(h2 / d2);
    out = {p - h, p + h};
  }
  return 1 + sgn(h2);
}

signed main() { __
  pair<Point, Point> ret;
  int x = circleCircle({5, 5}, 5, {10, 10}, 18.0277, ret);
  cout << x << ENDL;
  cout << ret.first.x << ' ' << ret.first.y << ENDL;
  cout << ret.second.x << ' ' << ret.second.y << ENDL;
  cout << (dist({5,5}, {10,10}) <= 5) << ENDL;
  cout << (dist({5,5}, {10,10}) <= 18.0277) << ENDL;
  return 0;
}