#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll be(ll a, ll b, ll m) {
  ll res = 1;
  a %= m;
  while (b) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  string ans = s;

  for (ll i = 0; i < n; i++) {
    ans[i] = s[i * be(2, k, n) % n];
  }

  cout << ans << '\n';

  return 0;
}