#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int MOD = 1e9 + 7;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n;
  cin >> n;

  ll ans = 1;
  for (int i = 0; i < n; i++) {
    ans *= 2;
    ans %= MOD;
  }

  cout << ans << '\n';

  return 0;
}