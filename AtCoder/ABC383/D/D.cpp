#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
using ll = long long;

vector<ll> primes;

void sieve(ll n) {
  vector<bool> is_prime(n + 1, 1);
  is_prime[0] = is_prime[1] = 0;
  for (ll p = 2; p <= n; p++) {
    if (!is_prime[p]) continue;
    for (ll i = p * p; i <= n; i += p) is_prime[i] = 0;
    primes.push_back(p);
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  sieve((int)2e6 + 500);

  ll n;
  cin >> n;

  ll x = (int)sqrt(n / 4);

  int r = (int)(lower_bound(primes.begin(), primes.end(), x) - primes.begin());

  auto pow8 = [&](ll x) -> ll {
    ll res = x;
    for (int i = 0; i < 7; i++) res *= x;
    return res;
  };

  ll ans = 0;

  for (int i = 0; i < SZ(primes); i++) {
    while (i < r && primes[i] * primes[i] * primes[r] * primes[r] > n) r--;
    if (i == r) break;
    ans += r - i;
  }

  for (int i = 0; i < SZ(primes); i++) {
    ll x = pow8(primes[i]);
    if (x > n) break;
    ans++;
  }

  cout << ans << '\n';

  return 0;
}