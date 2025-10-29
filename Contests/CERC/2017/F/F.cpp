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

int main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, p, r;
  cin >> n >> p >> r;

  if (r == 0) {
    if (n < p) {
      cout << "-1 -1" << '\n';
      return 0;
    }
    if (p - 1 > 1) {
      cout << p - 1 << ' ' << 1 << '\n';
      return 0;
    }
    if (p + 1 <= n) {
      cout << p + 1 << ' ' << 1 << '\n';
      return 0;
    }
  }

  if (n >= 2 * p) {
    cout << "-1 -1" << '\n';
    return 0;
  }
  if (n >= p) {
    ll x = 1;
    for (ll i = 1; i <= n; i++) {
      if (i == p) continue;
      x *= i;
      x %= p;
    }
    for (ll i = 1; i < p; i++) {
      if (x * i % p == r) {
        cout << p << ' ' << i << '\n';
        return 0;
      }
    }
    cout << "-1 -1" << '\n';
    return 0;
  }
  
  ll fact = 1;
  for (ll i = 1; i <= n; i++) {
    fact *= i;
    fact %= p;
  }
  ll inv = be(fact, p - 2, p);

  for (ll x = 2; x <= n; x++) {
    ll y = r * x % p * inv % p;
    if (y > 0 && y < x) {
      cout << x << ' ' << y << '\n';
      return 0;
    }
  }

  cout << "-1 -1" << '\n';
}