#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  ll sum = 0;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }

  if (sum % n != 0) {
    cout << "NO" << '\n';
    return;
  }

  ll x = sum / n;
  ll carry = 0;

  for (ll i = 0; i < n; i += 2) {
    if (a[i] > x) {
      carry += a[i] - x;
      a[i] = x;
    }
  }

  for (ll i = 0; i < n; i += 2) {
    if (a[i] < x) {
      carry -= (x - a[i]);
      a[i] = x;
    }
    if (carry < 0) {
      cout << "NO" << '\n';
      return;
    }
  }

  if (carry != 0) {
    cout << "NO" << '\n';
    return;
  }

  carry = 0;

  for (ll i = 1; i < n; i += 2) {
    if (a[i] > x) {
      carry += a[i] - x;
      a[i] = x;
    }
  }

  for (ll i = 1; i < n; i += 2) {
    if (a[i] < x) {
      carry -= (x - a[i]);
      a[i] = x;
    }
    if (carry < 0) {
      cout << "NO" << '\n';
      return;
    }
  }

  if (carry != 0) {
    cout << "NO" << '\n';
    return;
  }

  cout << "YES" << '\n';
}

signed main() {
  ll tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  
  return 0;
}