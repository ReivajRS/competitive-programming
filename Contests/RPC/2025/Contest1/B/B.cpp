#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

const double EPS = 1e-6;
signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  double p;

  cin >> n >> p;

  double ans = 0;
  vector<pair<double, double>> less, more;
  for (int i = 0; i < n; i++) {
    double c;
    double p2;
    cin >> c >> p2;
    if (abs(p2-p)<EPS) {
      ans += c;
      continue;
    }
    if (p2 < p) {
      less.push_back({p - p2, c});
    }
    if (p2 > p) {
      more.push_back({p2 - p, c});
    }
  }

  sort(less.rbegin(), less.rend());
  sort(more.rbegin(), more.rend());

  while (!less.empty() && !more.empty()) {
    auto [p1, c1] = less.back();
    auto [p2, c2] = more.back();
    double need = p1 * c1 / p2;
    if (c2 >= need) {
      c2 -= need;
      ans += need + c1;
      less.pop_back();
      if (abs(c2) < EPS) {
        more.pop_back();
      }
      else {
        more.back().second = c2;
      }
    }
    else {
      need = p2 * c2 / p1;
      c1 -= need;
      ans += need + c2;
      more.pop_back();
      if (abs(c1) < EPS) {
        less.pop_back();
      }
      else {
        less.back().second = c1;
      }
    }
  }

  cout << fixed << setprecision(8);
  cout << ans << '\n';

  return 0;
}