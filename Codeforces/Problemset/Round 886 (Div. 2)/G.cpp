#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using point = pair<ll, ll>;
using line = tuple<ll, ll, ll>;

line normalize(ll a, ll b, ll c) {
  if (a < 0 || (a == 0 && b < 0) || (a == 0 && b == 0 && c < 0)) {
    a *= -1;
    b *= -1;
    c *= -1;
  }
  ll g = gcd(a, gcd(b, c));
  a /= g, b /= g, c /= g;
  return {a, b, c};
}

line get_line(point p1, point p2) {
  auto [x1, y1] = p1;
  auto [x2, y2] = p2;
  int a = y1 - y2, b = x2 - x1, c = -(a * x1 + b * y1);
  return normalize(a, b, c);
}

void solve() {
  int n;
  cin >> n;

  vector<point> pts(n);
  for (int i = 0; i < n; i++) {
    cin >> pts[i].first >> pts[i].second;
  }

  map<line, int> line_cnt;
  
  vector<int> dx = {1, 1, 0, -1};
  vector<int> dy = {0, 1, 1, 1};

  for (auto [x, y] : pts) {
    for (int i = 0; i < int(dx.size()); i++) {
      ll xx = x + dx[i], yy = y + dy[i];
      line l = get_line({x, y}, {xx, yy});
      line_cnt[l]++;
    }
  }

  ll ans = 0;
  for (auto [x, y] : pts) {
    for (int i = 0; i < int(dx.size()); i++) {
      ll xx = x + dx[i], yy = y + dy[i];
      line l = get_line({x, y}, {xx, yy});
      ans += line_cnt[l] - 1;
    }
  }

  cout << ans << '\n';
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