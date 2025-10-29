#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())

using ll = long long;
using ld = long double;
using T = ll;
constexpr double EPS = 1e-15;

struct p3 {
  T x, y, z;
  p3() { x = 0, y = 0, z = 0; }
  p3(T _x, T _y, T _z) { x = _x, y = _y, z = _z; }
  p3 operator+(p3 p) const { return {x + p.x, y + p.y, z + p.z}; }
  p3 operator-(p3 p) const { return {x - p.x, y - p.y, z - p.z}; }

  T dot(p3 p) {
    return x * p.x + y + p.y + z * p.z;
  }
  T sq() {
    // p3 p = *this;
    return (*this).dot(*this);
  }
  ld abs() {
    return sqrt(sq());
  }
  p3 cross(p3 p) const {
    return {
      y * p.z - z * p.y,
      z * p.x - x * p.z,
      x * p.y - y * p.x
    };
  }
};

ld dist(p3 p, p3 q) {
  return (p - q).abs();
}

struct plane {
  p3 n;
  T d;
  plane(p3 n, p3 p) : n(n), d(n.dot(p)) {}
  plane(p3 p, p3 q, p3 r) : plane((q - p).cross(r - p), p) {}
  T side(p3 p) {
    return n.dot(p) - d;
  }
  ld dist(p3 p) {
    return abs(side(p)) / n.abs();
  }
};

bool areCollinear(p3 a, p3 b, p3 c) {
  p3 v1 = c - a, v2 = b - a, res = v1.cross(v2);
  return res.x == 0 && res.y == 0 && res.z == 0;
}

ld check(int i, int j, int k, vector<p3>& pts) {
  plane pl(pts[i], pts[j], pts[k]);
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

  ld ans = 1e18;

  // for (int i = 0; i < n; i++) {
  //   for (int j = i + 1; j < n; j++) {
  //     vector<int> onLine = {i, j};
  //     vector<int> outLine;
  //     for (int k = 0; k < n; k++) {
  //       if (k == i || k == j) {
  //         continue;
  //       }
  //       if (areCollinear(pts[i], pts[j], pts[k])) {
  //         onLine.push_back(k);
  //       }
  //       else {
  //         outLine.push_back(k);
  //       }
  //     }
  //     if (SZ(outLine) >= 2) {
  //       vector<int> onLine2 = {outLine[0], outLine[1]};
  //       for (int k = 2; k < SZ(outLine); k++) {
  //         if (areCollinear(pts[outLine[0]], pts[outLine[1]], pts[outLine[k]])) {
  //           onLine2.push_back(outLine[k]);
  //         }
  //       }
  //       if (SZ(onLine) + SZ(onLine2) == n) {
  //         ld mx = 0;
  //         bool f = 0, ok = 1;
  //         for (auto idx1 : onLine) {
  //           for (auto idx2 : onLine2) {
  //             ld d = dist(pts[idx1], pts[idx2]);
  //             if (f && abs(mx - d) > EPS) {
  //               ok = 0;
  //               break;
  //             }
  //             mx = max(mx, dist(pts[idx1], pts[idx2]));
  //             f = 1;
  //           }
  //           if (!ok) {
  //             break;
  //           }
  //         }
  //         if (ok) {
  //           ans = min(ans, mx);
  //         }
  //       }
  //     }
  //   }
  // }

  cout << setprecision(20) << fixed;
  
  if (n <= 3) {
    cout << 0 << '\n';
    return 0;
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        if (!areCollinear(pts[i], pts[j], pts[k])) {
          ans = min(ans, check(i, j, k, pts));
        }
      }
    }
  }

  if (ans >= 1e18) {
    ans = 0;
  }

  cout << ans << '\n';

  return 0;
}