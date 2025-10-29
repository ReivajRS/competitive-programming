#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
using ll = long long;

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> a(n), b(m);
  unordered_set<int> mpa, mpb;
  int suma = 0, sumb = 0;
  for (auto &x : a) {
    cin >> x;
    suma += x;
  }
  for (auto &x : b) {
    cin >> x;
    sumb += x;
  }
  for (auto &x : a) {
    mpa.insert(suma - x);
  }
  for (auto &x : b) {
    mpb.insert(sumb - x);
  }
  auto is_possible = [&](int v1, int v2) -> bool {
    return (mpa.count(v1) && mpb.count(v2)) || (mpa.count(v2) && mpb.count(v1));
  };
  unordered_map<int, bool> memo;
  while (q--) {
    int x;
    cin >> x;
    if (memo.count(x)) {
      cout << (memo[x] ? "YES" : "NO") << '\n';
      continue;
    }
    bool flag = 0;
    for (ll y = 1; y * y <= abs(x); y++) {
      if (x % y == 0) {
        int v1 = y, v2 = x / y;
        // cout << v1 << ' ' << v2 << '\n';
        if (is_possible(v1, v2) || is_possible(-v1, -v2)) {
          cout << "YES" << '\n';
          memo[x] = 1;
          flag = 1;
          break;
        }
      }
    }
    if (!flag) {
      cout << "NO" << '\n';
      memo[x] = 0;
    }
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  // cin >> tc;
  tc = 1;
  while (tc--) {
    solve();
  }

  return 0;
}