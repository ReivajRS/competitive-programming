#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)(x).size())

int get_area(vector<pair<int, int>>& pts) {
  int area = 0, n = SZ(pts);
  for (int i = 0; i < n; i++) {
    int ii = (i + 1) % n;
    area += pts[i].first * pts[ii].second - pts[ii].first * pts[i].second;
  }
  return abs(area) / 2;
}

void solve() {
  int n, A;
  cin >> n >> A;
  vector<pair<int, int>> pts;
  if (n == 3) {
    pts.push_back({0, 0});
    pts.push_back({1, 2 * A});
    pts.push_back({1, 0});
  }
  else if (n == 4) {
    pts.push_back({0, 0});
    pts.push_back({0, A});
    pts.push_back({1, A});
    pts.push_back({1, 0});
  }
  else {
    int base = (n - 1) / 2;
    if (base > A) {
      cout << "No" << '\n';
      return;
    }

    int x = 0, y = 0;
    for (int i = 0; i < n - 1; i++) {
      pts.push_back({x, y});
      if (y == 0) {
        x++, y++;
      }
      else {
        y--;
      }
    }

    if (n & 1) {
      pts.push_back({(A - base) * 2 + base, -1});
    }
    else {
      pts.back().first = A;
      pts.push_back({0, -1});
    }

    // printf("Puntos\n");
    // for (int i = 0; i < n; i++) {
    //   auto [x, y] = pts[i];
    //   // printf("(%d, %d)\n", x, y);
    //   printf("(%d, %d), ", x, y);
    // }

    // printf("Area = %d\n", get_area(pts));
  }
  cout << "Yes" << '\n';
  for (auto &[x, y] : pts) {
    cout << x << ' ' << y << '\n';
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  
  return 0;
}