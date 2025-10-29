#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
#include <assert.h>
using namespace std;

using ld = long double;
constexpr ld EPS = 1e-14;

struct p3 {
  ld x, y, z;
  p3 operator+(p3 p) const { return {x + p.x, y + p.y, z + p.z}; }
  p3 operator-(p3 p) const { return {x - p.x, y - p.y, z - p.z}; }
  p3 operator*(ld d) const { return {x * d, y * d, z * d}; }
  p3 operator/(ld d) const { return {x / d, y / d, z / d}; }
  ld dot(p3 p) {
    return x * p.x + y * p.y + z * p.z;
  }
  ld sq() {
    return dot(*this);
  }
  ld abs() {
    return sqrtl(sq());
  }
  p3 unit() {
    return (*this) / abs();
  }
  p3 cross(p3 p) {
    return {
      y * p.z - z * p.y,
      z * p.x - x * p.z,
      x * p.y - y * p.x
    };
  }
};

struct pt {
  ld x, y;
  pt operator+(pt p) const { return {x + p.x, y + p.y}; }
  pt operator-(pt p) const { return {x - p.x, y - p.y}; }
  pt operator*(ld d) const { return {x * d, y * d}; }
  pt operator/(ld d) const { return {x / d, y / d}; }
  ld dot(pt p) { return x * p.x + y * p.y; }
  ld sq() { return x * x + y * y; }
  ld abs() { return sqrtl(sq()); }
  pt perp() { return {-y, x}; }
};

struct coords {
  p3 o, dx, dy, dz;
  coords(p3 p, p3 q, p3 r) : o(p) {
    dx = (q - p).unit();
    dz = (dx.cross(r - p)).unit();
    dy = dz.cross(dx);
  }
  pt pos2d(p3 p) { return {(p - o).dot(dx), (p - o).dot(dy)}; }
};

vector<pt> tangets(pt o1, ld r1, pt o2, ld r2) {
  pt d = o2 - o1;
  ld dr = r1 - r2, d2 = d.sq(), h2 = d2 - dr * dr;
  vector<pt> out;
  for (ld sign : {-1, 1}) {
    pt v = (d * dr + d.perp() * sqrtl(h2) * sign) / d2;
    out.push_back(o1 + v * r1);
  }
  return out;
}

ld angle(pt a, pt b) {
  ld cosTheta = a.dot(b) / a.abs() / b.abs();
  return acosl(max(ld(-1.0), min(ld(1.0), cosTheta)));
}

ld angle(pt o, pt a, pt b) {
  return angle(a - o, b - o);
}

ld calc(pt c, ld r, pt a, pt ta, pt b, pt tb) {
  ld ans = (a - ta).abs() + (b - tb).abs();
  ans += r * angle(c, ta, tb);
  return ans;
}

ld solve(pt a, pt b, pt c, ld r) {
  vector<pt> tana = tangets(c, r, a, 0);
  vector<pt> tanb = tangets(c, r, b, 0);
  ld ans = 1e15;
  for (int i = 0; i < (int)tana.size(); i++) {
    for (int j = 0; j < (int)tanb.size(); j++) {
      ans = min(ans, calc(c, r, a, tana[i], b, tanb[j]));
    }
  }
  return ans;
}

struct line3d {
  p3 d, o;
  line3d() {
    d = {0, 0, 0}, o = {0, 0, 0};
  }
  line3d(p3 p, p3 q) { d = q - p, o = p; }
  ld sqDist(p3 p) {
    return (d.cross(p - o)).sq() / d.sq();
  }
  ld dist(p3 p) {
    return sqrtl(sqDist(p));
  }
  p3 proj(p3 p) {
    return o + d * (d.dot(p - o)) / d.sq();
  }
};

int sphereLine(p3 o, ld r, line3d l, pair<p3, p3> &out) {
  ld h2 = r * r - l.sqDist(o);
  if (h2 < 0) return 0;
  p3 p = l.proj(o);
  p3 h = l.d * sqrtl(h2) / l.d.abs();
  out = {p - h, p + h};
  return 1 + (h2 > 0);
}

signed main() {
  p3 a, b, c;
  cin >> a.x >> a.y >> a.z;
  cin >> b.x >> b.y >> b.z;
  cin >> c.x >> c.y >> c.z;
  ld r;
  cin >> r;

  line3d l_ab(a, b);
  
  pair<p3, p3> inter;
  int cnt1 = sphereLine(c, r, l_ab, inter);

  int cnt2 = 0;
  if (cnt1 > 0 && fabsl((c - inter.first).abs() - r) < EPS) {
    cnt2++;
  }
  if (cnt1 > 1 && fabsl((c - inter.second).abs() - r) < EPS) {
    cnt2++;
  }
  
  if (cnt2 < 2) {
    cout << (a - b).abs() << '\n';
    return 0;
  }

  cout << setprecision(10) << fixed;

  ld ans = 1e15;

  p3 vn = (c - a).cross(c - b);
  if (fabsl(vn.x) < EPS && fabsl(vn.y) < EPS && fabsl(vn.z) < EPS) {
      ans = min(ans, solve({-(c - a).abs(), 0}, {(c - b).abs(), 0}, {0, 0}, r));
  }
  else {
    coords mapper(a, b, c);
    pt a2 = mapper.pos2d(a);
    pt b2 = mapper.pos2d(b);
    pt c2 = mapper.pos2d(c);
    ans = min(ans, solve(a2, b2, c2, r));
  }

  cout << ans << '\n';
}