#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

using T = long long;
using ld = long double;

struct p3 {
  T x, y, z;
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
  bool operator==(p3 p) const {
    return tie(x, y, z) == tie(p.x, p.y, p.z);
  }
  T dot(p3 w) {
    return x * w.x + y * w.y + z * w.z;
  }
  T sq(){
    return (*this).dot(*this);
  }
  ld abs() {
    return sqrtl(sq());
  };
  p3 cross(p3 p) const {
    return {
      y * p.z - z * p.y,
      z * p.x - x * p.z,
      x * p.y - y * p.x
    };
  }
};

struct plane{
  p3 n;
  T d;
  plane(p3 n,T d):n(n),d(d){}
  plane(p3 n,p3 p): n(n), d(n.dot(p)) {}
  plane(p3 p,p3 q,p3 r): plane((q-p)*(r-p),p) {}
  T side(p3 p){
    return n.dot(p) - d;
  }
  ld dist(p3 p){
    return abs(side(p)) / n.abs();
  }
  p3 proj(p3 p) {
    return p - n * side(p) / n.sq();
  }
};

ld check(plane pl, vector<p3>& pts) {
  bool left = 0, right = 0;
  ld ret = 0;
  for (p3 p : pts) {
    ll ori = pl.side(p);
    if (!ori) {
      continue;
    }
    ret = max(ret, pl.dist(p));
    if (ori < 0) {
      left = 1;
    }
    else {
      right = 1;
    }
  }
  return !left || !right ? ret : 1e18;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<p3> pts(n);
  for (auto &[x, y, z] : pts) {
    cin >> x >> y >> z;
  }

  if(n <= 3){
    cout << 0 << ENDL;
    return 0;
  }

  ld ans = 1e18;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (j == i) continue;
      for (int k = 0; k < n; k++) {
        if (k == j || k == i) continue;
        p3 v1 = pts[j] - pts[i];
        p3 v2 = pts[k] - pts[i];
        p3 vn = v1.cross(v2);
        if (vn == p3{0, 0, 0}) {
          continue;
        }
        ans = min(ans, check(plane(pts[i], pts[j], pts[k]), pts));
        for (int l = k + 1; l < n; l++) {
          if (l == i || l == j || l == k) continue;
          v2 = pts[k] - pts[l];
          vn = v1.cross(v2);
          if (vn == p3{0, 0, 0}) {
            continue;
          }
          ans = min(ans, check(plane(vn, pts[i]), pts));
        }
      }
    }
  }

  if(ans >=1e18){
    ans = 0;
  }
  cout << setprecision(12) << fixed;
  cout << ans << ENDL;
  
  return 0;
}