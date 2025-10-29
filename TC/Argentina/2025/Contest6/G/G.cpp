#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) (int(x.size()))
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  constexpr int maxn = 1e5 + 5;
  vector<int> primes;
  vector<bool> is_prime(maxn, 1);
  is_prime[0] = is_prime[1] = 0;
  for (int i = 2; i < maxn; i++) {
    if (!is_prime[i]) {
      continue;
    }
    for (int j = 2 * i; j < maxn; j += i) {
      is_prime[j] = 0;
    }
    primes.push_back(i);
  }

  int t;
  cin >> t;

  while (t--) {
    ll n;
    cin >> n;
    ll ans = 1;
    for (auto p : primes) {
      if (n % p != 0) {
        continue;
      }
      int cnt = 0;
      while (n % p == 0) {
        cnt++;
        n /= p;
      }
      ans += ans * cnt * 2;
    }
    if (n != 1) {
      ans += ans * 2;
    }
    ans /= 2;
    cout << ans + 1 << '\n';
  }

  return 0;
}