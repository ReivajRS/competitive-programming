#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

vector<ll> primes;

void sieve(int n) {
  vector<bool> is_prime(n + 1, 1);
  is_prime[0] = is_prime[1] = 0;
  for (ll p = 2; p <= n; p++) {
    if(!is_prime[p])continue;
    for(ll i=p*p;i<=n;i+=p)is_prime[i]=0;
    primes.push_back(p);
  }
}

vi prime_factors(int n) {
  vi factors;
  for (auto p : primes) {
    if (1ll * p * p > n) break;
    if (n % p == 0) factors.pb(p);
    while (n % p == 0) n /= p;
  }
  if (n != 1) factors.pb(n);
  return factors;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  sieve(100001);

  int n;
  cin >> n;

  vi a(n);
  for (auto &x : a) cin >> x;

  vi dp(100001, 0);
  int ans = 1;

  FOR (i, 0, n) {
    vi factors = prime_factors(a[i]);
    for (auto p : factors) {
      dp[a[i]] = max(dp[a[i]], dp[p] + 1);
    }
    for (auto p : factors) {
      dp[p] = max(dp[p], dp[a[i]]);
    }
    ans = max(ans, dp[a[i]]);
  }

  cout << ans << ENDL;
  
  return 0;
}