#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

const int maxn = 500005, MOD = 998244353;

ll binpow(ll a, ll b, ll m) {
  ll res = 1;
  a %= m;
  while (b) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

ll inv[maxn];
void precalc_inverse(int m) {
  inv[0] = 1, inv[1] = 1;
  for (int i = 2; i < maxn; i++) {
    inv[i] = m - (m/i) * inv[m%i] % m;
  }
}

ll fact[maxn];
void precalc_fact(int m) {
  fact[0] = 1;
  for (int i = 1; i < maxn; i++) {
    fact[i] = fact[i - 1] * i;
  }
}

ll invfact[500005];
void precalc_invfact() {
  precalc_inverse(MOD);
  precalc_fact(MOD);
  invfact[1] = 1;
  for (int i = 2; i < maxn; i++) invfact[i] = invfact[i - 1] * inv[i] % MOD;
}

ll comb(int n, int k) {
  if (n < k) return 0;
  return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
}

void solve() {
  int len = 0;
  vector<int> c(26);
  for (auto &x : c) {
    cin >> x;
    len += x;
  }
  int even = len / 2;
  int odd = len - even;

}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  cin >> tc;

  while (tc--) {
    solve();
  }

  return 0;
}