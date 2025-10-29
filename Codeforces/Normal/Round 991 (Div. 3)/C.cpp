#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  string s;
  cin >> s;
  ll n = (ll)s.size();
  ll sum = 0;
  ll n2 = 0, n3 = 0;
  for (char c : s) {
    sum += (c - '0');
    n2 += (c == '2');
    n3 += (c == '3');
  }

  if (sum % 9 == 0) {
    cout << "YES" << '\n';
    return;
  }

  ll rem = sum % 9;
  for (ll i = 1; i <= n3; i++) {
    rem += 6;
    rem %= 9;
    if (rem == 0) {
      cout << "YES" << '\n';
      return;
    }
    ll dif = 9 - rem;
    if (dif % 2 == 0 && dif / 2 <= n2) {
      cout << "YES" << '\n';
      return;
    }
  }

  rem = sum % 9;
  for (ll i = 1; i <= n2; i++) {
    rem += 2;
    rem %= 9;
    if (rem == 0) {
      cout << "YES" << '\n';
      return;
    }
    ll dif = 9 - rem;
    if (dif % 6 == 0 && dif / 6 <= n3) {
      cout << "YES" << '\n';
      return;
    }
  }

  cout << "NO" << '\n';
}

signed main() {
  ll tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  
  return 0;
}