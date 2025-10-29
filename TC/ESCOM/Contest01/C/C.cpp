#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

int n;
int a[51], b[51];
map<tuple<int, int, int>, ll> dp;

ll solve(int i, int gcd1, int gcd2) {
  if (i == n) {
    return lcm((ll)gcd1, (ll)gcd2);
  }
  if (dp.count({i, gcd1, gcd2})) {
    return dp[{i, gcd1, gcd2}];
  }
  return dp[{i, gcd1, gcd2}] = max(solve(i + 1, gcd(gcd1, a[i]), gcd(gcd2, b[i])), solve(i + 1, gcd(gcd1, b[i]), gcd(gcd2, a[i])));
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }

  cout << solve(0, 0, 0) << '\n';

  return 0;
}