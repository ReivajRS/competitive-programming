#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)(x).size())

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<pair<int, int>> pts;
  int n = 5, x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    pts.push_back({x, y});
    if (y == 0) {
      x++, y++;
    }
    else {
      y--;
    }
  }

  printf("Puntos\n");
  for (int i = 0; i < n; i++) {
    auto [x, y] = pts[i];
    printf("(%d, %d)\n", x, y);
  }

  int area = 0;
  for (int i = 0; i < n; i++) {
    int ii = (i + 1) % n;
    area += pts[i].first * pts[ii].second - pts[ii].first * pts[i].second;
  }
  area = abs(area) / 2;

  printf("Area = %d\n", area);
  
  return 0;
}