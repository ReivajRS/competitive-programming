#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;

void solve() {
  ll n;
  cin >> n;
  
  vector<ll> p(n), s(n);
  for (ll i = 0; i < n; i++) {
    cin >> p[i];
  }
  for (ll i = 0; i < n; i++) {
    cin >> s[i];
  }

  vector<ll> a(n);
  for (ll i = 0; i < n; i++) {
    a[i] = lcm(p[i], s[i]);
  }

  ll p_gcd = 0;
  for (ll i = 0; i < n; i++) {
    p_gcd = gcd(p_gcd, a[i]);
    if (p_gcd != p[i]) {
      cout << "NO" << '\n';
      return;
    }
  }

  ll s_gcd = 0;
  for (ll i = n - 1; i >= 0; i--) {
    s_gcd = gcd(s_gcd, a[i]);
    if (s_gcd != s[i]) {
      cout << "NO" << '\n';
      return;
    }
  }

  cout << "YES" << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  ll tc;
  cin >> tc;

  while (tc--) {
    solve();
  }
  
  return 0;
}