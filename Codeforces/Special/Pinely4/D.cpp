#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

vector<ll> primes;
void sieve(ll n) {
  vector<bool> is_prime(n + 1, 1);

  is_prime[0] = is_prime[1] = 0;
  for (ll p = 2; p <= n; p++) {
    if (is_prime[p]) {
      for (ll i = p * p; i <= n; i += p) is_prime[i] = 0;
      primes.push_back(p);
    }
  }
}

ll p_cnt(ll x) {
  return lower_bound(ALL(primes), x) - primes.begin() + binary_search(ALL(primes), x);
}

vi seq;

void precalc_seq(ll n) {
  FOR (i, 2, n + 2) {
    seq.pb(p_cnt(i));
  }
}

void solve() {
  ll n;
  cin >> n;
  cout << seq[n - 1] << ENDL;
  FOR (i, 0, n) {
    cout << seq[i] << " \n"[i == n - 1];
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  sieve(300100);
  precalc_seq(300050);
  
  ll tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  
  return 0;
}