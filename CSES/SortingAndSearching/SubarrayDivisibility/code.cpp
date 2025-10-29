#include <bits/stdc++.h>
using namespace std;

using ll = long long;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  map<ll, int> mp;
  mp[0] = 1;
  ll sum = 0;
  ll cnt = 0;

  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    sum += v;
    ll mod = (sum % n + n) % n;
    cnt += mp[mod];
    mp[mod]++;
  }

  cout << cnt << '\n';

  return 0;
}