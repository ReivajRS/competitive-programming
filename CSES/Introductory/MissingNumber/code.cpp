#include <bits/stdc++.h>
using namespace std;

using ll = long long;

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  ll n;
  cin >> n;
  ll sum = n * (n + 1) / 2;

  for (int i = 0; i < n - 1; i++) {
    ll x;
    cin >> x;
    sum -= x;
  }

  cout << sum << '\n';
  
  return 0;
}