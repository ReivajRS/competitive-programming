#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

void solve() {
  ll n, k;
  cin >> n >> k;
  
  if (n <= 42 && k > (1ll << (n - 1))) {
    cout << -1 << '\n';
    return;
  }

  vector<bool> b;
  k--;
  while (k) {
    b.push_back(k % 2);
    k /= 2;
  }
  while (SZ(b) < n - 1) {
    b.push_back(0);
  }
  
  int lp = 0, rp = n - 1, x = 1;
  vector<int> ans(n);

  for (int i = SZ(b) - 1; i >= 0; i--) {
    if (b[i]) {
      ans[rp--] = x++;
    }
    else {
      ans[lp++] = x++;
    }
  }
  ans[lp] = x;

  for (int i = 0; i < n; i++) {
    cout << ans[i] << " \n"[i == n - 1];
  }
}

/*
  1 2 3 4 5
  1 2 3 5 4
  1 2 4 5 3
  1 2 5 4 3
  1 3 4 5 2
  1 3 5 4 2
  1 4 5 3 2
  1 5 4 3 2
  2 3 4 5 1
  2 3 5 4 1
  2 4 5 3 1
  2 5 4 3 1
  3 4 5 2 1
  3 5 4 2 1
  4 5 3 2 1
  5 4 3 2 1
*/

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }

  return 0;
}