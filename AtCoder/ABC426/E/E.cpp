#include <bits/stdc++.h>
using namespace std;

struct Point {
  double x, y;
};

void solve() {
  vector<Point> T(2);
  cin >> T[0].x >> T[0].y >> T[1].x >> T[1].y;
  vector<Point> A(2);
  cin >> A[0].x >> A[0].y >> A[1].x >> A[1].y;

  double dist_T = hypot(T[1].x - T[1].x, T[1].y - T[0].y);
  double dist_A = hypot(A[1].x - A[1].x, A[1].y - A[0].y);

  auto getT = [&](int t) -> Point {
    return {T[0].x + t * (T[1].x - T[0].x) / dist_T, T[0].y + t * (T[1].y - T[0].y) / dist_T};
  };
  auto getA = [&](int t) -> Point {
    return {A[0].x + t * (A[1].x - A[0].x) / dist_A, A[0].y + t * (A[1].y - A[0].y) / dist_A};
  };

  
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}