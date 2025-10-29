#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
#define SZ(x) ((ll)(x).size())

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll d = a[1] - a[0];
  for (ll i = 1; i < n - 1; i++) {
    if (a[i + 1] - a[i] != d) {
      cout << "NO" << '\n';
      return;
    }
  }
  ll b = a[0] - d;
  if (b % (n + 1) != 0 || b < 0) {
    cout << "NO" << '\n';
    return;
  }
  ll y = b / (n + 1);
  ll x = d + y;
  if (x < 0 || y < 0) {
    cout << "NO" << '\n';
    return;
  }
  cout << "YES" << '\n';
  /*
    ai = x*i + y*(n - i + 1)
    ai = (x - y)*i + y*(n + 1)
    d = x - y
    b = y*(n + 1)
    ai = d*i + b
    a1 = d*1 + b
    b = a1 - d
    y = b / (n + 1)
    x = d + y
  */
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