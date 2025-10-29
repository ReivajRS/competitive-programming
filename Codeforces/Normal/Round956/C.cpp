#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<vector<ll>> pref(3, vector<ll>(n + 1));
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;
      pref[i][j + 1] = pref[i][j] + x;
    }
  }

  ll tot = pref[0][n];
  ll target = (tot + 2) / 3;

  vector<int> l(3), r(3);

  auto check = [&](int a, int b, int c, int i) -> bool {
    if (pref[a][i] >= target) {
      int j = int(lower_bound(pref[b].begin(), pref[b].end(), pref[b][i] + target) - pref[b].begin());
      if (j < n) {
        if (pref[c][n] - pref[c][j] >= target) {
          l[a] = 1, r[a] = i;
          l[b] = i + 1, r[b] = j;
          l[c] = j + 1, r[c] = n;
          return true;
        }
      }
    }
    return false;
  };

  for (int i = 1; i < n; i++) {
    vector<int> p = {0, 1, 2};
    do {
      if (check(p[0], p[1], p[2], i)) {
        for (int j = 0; j < 3; j++) {
          cout << l[j] << ' ' << r[j] << ' ';
        }
        cout << '\n';
        return;
      }
    }
    while (next_permutation(p.begin(), p.end()));
  }

  cout << -1 << '\n';
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