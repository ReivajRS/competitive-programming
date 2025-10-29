#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((ll)x.size())

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, p, h;
  cin >> n >> p >> h;

  vector<ll> add_values, mul_values;
  ll attacks = 0;

  for (ll i = 0; i < n; i++) {
    char c;
    cin >> c;
    if (c == '!') {
      attacks++;
      continue;
    }
    ll x;
    cin >> x;
    if (c == '*') {
      mul_values.push_back(x);
    }
    else {
      add_values.push_back(x);
    }
  }

  sort(add_values.rbegin(), add_values.rend());
  sort(mul_values.rbegin(), mul_values.rend());

  ll add_total = 0, mul_total = 1;
  bool exceeds = 0;
  for (auto x : add_values) {
    add_total += x;
  }
  for (auto x : mul_values) {
    mul_total *= x;
    if (mul_total >= (ll)1e9) {
      exceeds = 1;
      break;
    }
  }

  if (attacks == 0 || (p == 0 && add_total == 0)) {
    cout << '*' << '\n';
    return 0;
  }
  
  auto brute = [&](ll power, ll rem_h) -> ll {
    ll mn = 1e9;
    for (ll i = 0; i <= SZ(add_values); i++) {
      ll curr = power;
      for (ll j = 0; j <= SZ(mul_values); j++) {
        for (ll k = 1; k <= attacks; k++) {
          if(curr * k >= rem_h) {
            mn = min(mn, i + j + k);
          }
        }
        if (curr >= (ll)1e9) {
          break;
        }
        if(j < SZ(mul_values)) {
          curr *= mul_values[j];
        }
      }
      if (i < SZ(add_values)) {
        power += add_values[i];
      }
    }
    return mn;
  };

  
  if (add_total == 0 && mul_total == 1) {
    ll cnt = h / (attacks * p);
    if (cnt * attacks * p == h) {
      cout << (cnt - 1) * n + attacks << '\n';
      return 0;
    }
    cout << cnt * n + brute(p, h - cnt * attacks * p) << '\n';
    return 0;
  }
  
  if (exceeds) {
    cout << brute(p, h) << '\n';
    return 0;
  }

  ll last_pow = 0, now_pow = p;
  ll cnt = 0;
  ll pows_sum = 0;
  while (pows_sum * attacks < h) {
    last_pow = now_pow;
    now_pow = (last_pow + add_total) * mul_total;
    pows_sum += now_pow;
    cnt++;
  }
  if (pows_sum * attacks == h) {
    cout << (cnt - 1) * n + attacks << '\n';
    return 0;
  }
  pows_sum -= now_pow;
  ll power = last_pow;
  ll rem_h = h - pows_sum * attacks;
  cout << (cnt - 1) * n + brute(power, rem_h) << '\n';

  return 0;
}