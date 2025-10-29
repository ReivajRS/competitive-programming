#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

using i64 = long long;

constexpr int maxn = 1e5 + 1;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<int> primes;
  {
    vector<bool> is_prime(maxn, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < maxn; ++i) {
      if (!is_prime[i]) {
        continue;
      }
      primes.push_back(i);
      for (int j = i + i; j < maxn; j += i) {
        is_prime[j] = false;
      }
    }
  }

  int q;
  cin >> q;
  while (q--) {
    i64 n;
    cin >> n;
    i64 aux = n, ans = 1;
    for (int p : primes) {
      if (p > aux) {
        break;
      }
      if (aux % p != 0) {
        continue;
      }
      int e = 0;
      while (aux % p == 0) {
        ++e;
        aux /= p;
      }
      ans = ans + ((e * ans) << 1);
    }
    if (aux != 1) {
      ans = ans + (ans << 1);
    }
    ans = (ans + 1) >> 1;
    cout << ans << '\n';
  }

  return 0;
}