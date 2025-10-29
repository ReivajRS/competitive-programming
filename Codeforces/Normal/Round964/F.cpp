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

const int MOD = 1e9 + 7;
const int maxn = 2e5 + 5;

ll inv[maxn];
void precalc_inv(int m) {
  inv[1] = 1;
  FOR(i, 2, maxn) {
    inv[i] = m - (m / i) * inv[m % i] % m;
  }
}

ll invfact[maxn];
void precalc_invfact() {
  precalc_inv(MOD);
  invfact[0] = invfact[1] = 1;
  for (int i = 2; i < maxn; i++) invfact[i] = invfact[i - 1] * inv[i] % MOD;
}

ll fact[maxn];
void precalc_fact() {
  fact[0] = fact[1] = 1;
  for (int i = 2; i < maxn; i++) fact[i] = fact[i - 1] * i % MOD;
}

ll comb(int n, int k) {
  if (n < k) return 0;
  return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
}

void solve() {
  int n, k;
  cin >> n >> k;
  vi a(n);
  int ones = 0;
  for (auto &x : a) {
    cin >> x;
    ones += x;
  }
  ll ans = 0;
  for (int i = (k + 1) / 2; i <= min(ones, k); i++) {
    ans += comb(ones, i) * comb(n - ones, k - i) % MOD;
    ans %= MOD;
  }
  cout << ans << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  precalc_invfact();
  precalc_fact();
  
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  
  return 0;
}