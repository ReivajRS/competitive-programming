#include <bits/stdc++.h>
using namespace std;

using ll = long long;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  ll s;
  cin >> n >> s;

  vector<int> a(n);
  vector<ll> pref(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pref[i + 1] = pref[i] + a[i];
  }

  ll sum = pref[n];
  unordered_set<ll> sumr;
  for (int i = 0; i <= n; i++) {
    sumr.insert(sum - pref[i]);
  }

  ll l = 0, r = ((ll)1e18 + sum - 1) / sum;
  while (l < r) {
    ll m = (l + r) / 2;
    ll x = m * sum;
    if (x < s) {
      l = m + 1;
    }
    else {
      r = m;
    }
  }

  l--;

  sum *= l;

  for (int i = 0; i <= n; i++) {
    if (sumr.count(s - (sum + pref[i]))) {
      cout << "Yes" << '\n';
      return 0;
    }
  }

  if (l) {
    l--;
    sum -= pref[n];
  }

  for (int i = 0; i <= n; i++) {
    if (sumr.count(s - (sum + pref[i]))) {
      cout << "Yes" << '\n';
      return 0;
    }
  }

  cout << "No" << '\n';

  return 0;
}