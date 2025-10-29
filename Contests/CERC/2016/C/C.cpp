#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i,a,b) for(int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'

const double PI = acos(-1.0);

typedef double T;

int sgn(T x) { return (T(0) < x) - (x < T(0)); }

struct Point {
  T x, y;

  Point operator+(Point p) const { return {x + p.x, y + p.y}; }
  Point operator-(Point p) const { return {x - p.x, y - p.y}; }

  Point operator*(T d) const { return {x * d, y * d}; }
  Point operator/(T d) const { return {x / d, y / d}; }

  T sq() { return x * x + y * y; }
  double norm() { return sqrt(sq()); }
  
  Point perp() { return {-y, x}; }

  T dot(Point p) { return x * p.x + y * p.y; }
};

double dist(Point p1, Point p2) { return hypot(p1.x - p2.x, p1.y - p2.y); }
bool isPerp(Point v, Point w) { return v.dot(w) == 0; }

double angle(Point v, Point w) { return acos(clamp(v.dot(w) / v.norm() / w.norm(), -1.0, 1.0)); }
double angle(Point o, Point a, Point b) {
  return angle(a - o, b - o);
}

int circleCircle(Point o1, double r1, Point o2, double r2, pair<Point, Point> &out) {
  Point d = o2 - o1;
  double d2 = d.sq();
  if (d2 == 0) {
    assert(r1 != r2);
    return 0;
  }
  double pd = (d2 + r1 * r1 - r2 * r2) / 2.0;
  double h2 = r1 * r1 - pd * pd / d2;
  if (h2 >= 0) {
    Point p = o1 + d * pd / d2, h = d.perp() * sqrt(h2 / d2);
    out = {p - h, p + h};
  }
  return 1 + sgn(h2);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cout << setprecision(9) << fixed;

  double H = sqrt(0.75), H_diff = 1.0 - H;

  int n;
  cin >> n;
  string S;
  cin >> S;
  bool t = 0, c = 0, s = 0;
  for (auto &ch : S) {
    t |= ch == 'T';
    c |= ch == 'C';
    s |= ch == 'S';
  }
  if (n == 1) {
    if (t) {
      cout << 3 << ENDL;
      return 0;
    }
    if (c) {
      cout << PI << ENDL;
      return 0;
    }
    cout << 4 << ENDL;
    return 0;
  }
  if (!c && !s) {
    cout << 2 + n + n - 1 << ENDL;
    return 0;
  };

  auto getXD = [&](int i) -> double {
    Point triangle_top = {0.5, H};
    Point medium_point = {(i + 1.0) / 2.0, (triangle_top.y + 0.5) / 2.0};
    Point circle_origin = {i + 0.5, 0.5};
    double r = dist(medium_point, circle_origin);
    pair<Point, Point> pts;
    circleCircle(medium_point, r, circle_origin, 0.5, pts);
    double d = dist(triangle_top, pts.second);
    double ang = angle(circle_origin, pts.second, {circle_origin.x, 1.0});
    d += ang / 2.0;
    return d;
  };

  auto chk = [&]() -> void {
    if (S[0] != 'T') return;
    int i = 1;
    while (S[i] == 'T') {
      ++i;
    }
    double ans = 1 + n;
    bool mid_c = S[i] == 'C';
    if (mid_c) {
      ans += getXD(i);
    } else {
      ans += hypot(H_diff, i - 0.5);
    }
    if (S[n - 1] == 'C') {
      ans += n - i - 1;
      ans += PI / 2;
      if (!mid_c) {
        ans += 0.5;
      }
      ans -= 0.5;
      cout << ans << ENDL;
      exit(0);
    }
    if (S[n - 1] == 'S') {
      ans += n - i + 1;
      if (mid_c) {
        ans -= 0.5;
      }
      cout << ans << ENDL;
      exit(0);
    }
    if (S[n - 1] == 'T') {
      int j = i, k = i;
      while (k < n) {
        if (S[k] != 'T') {
          j = k;
        }
        ++k;
      }
      ++ans;
      ans += j - i + 1;
      if (S[i] == 'C') {
        ans -= 0.5;
      }
      if (S[j] == 'C') {
        ans -= 0.5;
        ans += getXD(n - j - 1);
      } else {
        ans += hypot(H_diff, n - j - 1.5);
      }
      cout << ans << ENDL;
      exit(0);
    }        
    exit(0);
  };
  chk();
  reverse(ALL(S));
  chk();

  double ans = 2 * n + 2;
  if (S[0] == 'C') {
    ans += PI / 2 - 2;
  }
  if (S[n - 1] == 'C') {
    ans += PI / 2 - 2;
  }
  cout << ans << ENDL;

  return 0;
}