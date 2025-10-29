#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <assert.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using ld = long double;
using T = ld;

#define SZ(x) ((int)x.size())

constexpr T EPS = 1e-12;
const T PI = acos(-1.0l);

struct p3 {
  T x, y, z;
  p3() {
    x = 0, y = 0, z = 0;
  }
  p3(T _x, T _y, T _z) {
    x = _x, y = _y, z = _z;
  }
  p3 operator+(p3 p) const {
    return {x + p.x, y + p.y, z + p.z};
  }
  p3 operator-(p3 p) const {
    return {x - p.x, y - p.y, z - p.z};
  }
  p3 operator*(T d) const {
    return {x * d, y * d, z * d};
  }
  p3 operator/(T d) const {
    return {x / d, y / d, z / d};
  }
  p3 operator*(p3 w) const {
    return {
      y * w.z - z * w.y,
      z * w.x - x * w.z,
      x * w.y - y * w.x
    };
  }
  T dot(p3 w) {
    return x * w.x + y * w.y + z * w.z;
  }
  T sq() {
    return dot(*this);
  }
  ld abs() {
    return sqrtl(sq());
  };
  p3 unit() {
    return *this / abs();
  }
  void print(){
    cout << x << ' ' << y << ' ' << z << '\n';
  }
};

ld angle(p3 v, p3 w) {
  ld cosTheta = v.dot(w) / v.abs() / w.abs();
  return acosl(max(-1.0l, min(-1.0l, cosTheta)));
}

ld dist(p3 v, p3 w) {
  return (v-w).abs();
}

struct line3d {
  p3 d, o;
  line3d() {
    d = {0, 0, 0}, o = {0, 0, 0};
  }
  line3d(p3 p, p3 q) { d = q - p, o = p; }
  ld sqDist(p3 p) {
    return (d * (p - o)).sq() / d.sq();
  }
  ld dist(p3 p) {
    return sqrtl(sqDist(p));
  }
  p3 proj(p3 p) {
    return o + d*(d.dot(p - o)) / d.sq();
  }
};

int sphereLine(p3 o, ld r, line3d l, pair<p3, p3> &out) {
  ld h2 = r * r - l.sqDist(o);
  if (h2 < 0) return 0;
  p3 p = l.proj(o);
  p3 h = l.d*sqrtl(h2) / l.d.abs();
  out = {p - h, p + h};
  return 1 + (h2 > 0);
}

bool areCollinear(p3 a, p3 b, p3 c) {
  p3 ab = b - a, ac = c - a;
  p3 vn = ab * ac;
  return abs(vn.x) < EPS && abs(vn.y) < EPS && abs(vn.z) < EPS;
}

struct pt {
  T x, y;
  pt() {
    x = 0, y = 0;
  }
  pt(T _x, T _y) {
    x = _x, y = _y;
  }
  pt operator+(pt p) const { return {x + p.x, y + p.y}; }
  pt operator-(pt p) const { return {x - p.x, y - p.y}; }
  pt operator*(T d) const { return {x * d, y * d}; }
  pt operator/(T d) const { return {x / d, y / d}; }
  bool operator==(pt p) const {
    return abs(x - p.x) <= EPS && abs(y - p.y) <= EPS;
  }
  bool operator!=(pt p) const {
    return !((*this) == p);
  }

  T sq() { return x * x + y * y; }
  pt perp() { return {-y, x}; }
  T norm() { return sqrtl(sq()); }
  T dot(pt p) {
    return x * p.x + y * p.y;
  }
  T cross(pt p) const {
    return x * p.y - y * p.x;
  }
  T cross(pt a, pt b) const {
    return (a - *this).cross(b - *this);
  }
  void print(){
    cout << '(' << x << ", " << y << ')' << '\n';
  }
};

T dist(pt p1, pt p2) {
  return hypot(p1.x - p2.x, p1.y - p2.y);
}

T angle(pt v, pt w) {
  ld cosTheta = v.dot(w) / v.norm() / w.norm();
  return acos(max(-1.0l, min(1.0l, cosTheta)));
}

T angle(pt o, pt a, pt b) {
  return angle(a - o, b - o);
}

T distOnCircle(pt o, pt a, pt b, T r) {
  return r * angle(o, a, b);
}

struct coords {
  p3 o, dx, dy, dz;
  coords() {
    o = {0, 0, 0}, dx = {0, 0, 0}, dy = {0, 0, 0}, dz = {0, 0, 0};
  }
  coords(p3 p, p3 q, p3 r) {
    o = p;
    dx = (q - p).unit();
    dz = (dx * (r - p)).unit();
    dy = dz * dx;
  }
  pt pos2d(p3 p) {
    return {(p - o).dot(dx), (p - o).dot(dy)}; 
  }
};

int tangents(pt o1, ld r1, pt o2, ld r2, bool inner, vector<pair<pt, pt>> &out) {
  if (inner) r2 = -r2;
  pt d = o2 - o1;
  ld dr = r1 - r2, d2 = d.sq(), h2 = d2 - dr * dr;
  if (abs(d2) < EPS || h2 < 0) {
    assert(abs(h2) > EPS);
    return 0;
  }
  for (ld sign : {-1, 1}) {
    pt v = (d * dr + d.perp() * sqrtl(h2) * sign) / d2;
    out.push_back({o1 + v * r1, o2 + v * r2});
  }
  return 1 + (h2 > 0);
}

T calc(pt c, ld r, pt a, pt ta, pt b, pt tb) {
  T ans = dist(a, ta) + dist(b, tb);
  ans += distOnCircle(c, ta, tb, r);
  return ans;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  p3 a, b, c;

  cin >> a.x >> a.y >> a.z;
  cin >> b.x >> b.y >> b.z;
  cin >> c.x >> c.y >> c.z;
  ld r;
  cin >> r;

  line3d l_ab(a, b);
  
  pair<p3, p3> inter;
  int cnt = sphereLine(c, r, l_ab, inter);
  
  if (cnt < 2) {
    printf("%.10Lf\n", dist(a, b));
    return 0;
  }
  
  pt a2, b2, c2;
  
  if (areCollinear(a, b, c)) {
    a2 = {-(c - a).abs(), 0};
    b2 = {(c - b).abs(), 0};
    c2 = {0, 0};
  }
  else {
    coords mapper(a, b, c);
    a2 = mapper.pos2d(a);
    b2 = mapper.pos2d(b);
    c2 = mapper.pos2d(c);
  }

  vector<pair<pt, pt>> tan_a, tan_b;
  tangents(c2, r, a2, 0, 0, tan_a);
  tangents(c2, r, b2, 0, 0, tan_b);

  ld ans = 1e9;

  for (size_t i = 0; i < tan_a.size(); i++) {
    for (size_t j = 0; j < tan_b.size(); j++) {
      ans = min(ans, calc(c2, r, a2, tan_a[i].first, b2, tan_b[j].first));
    }
  }

  printf("%.10Lf\n", ans);

  return 0;
}