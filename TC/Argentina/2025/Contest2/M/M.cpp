#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  double n,r;
  cin >> n >> r;
  double ang = PI/n, y = 2*sin(ang), x = r*y / (2-y);
  cout << setprecision(9) << fixed << x << '\n';
}