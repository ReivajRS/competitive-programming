#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

using i64 = long long;

constexpr int MOD = 998244353;

inline int add(int x, int y) {
  return x + y >= MOD ? x + y - MOD : x + y;
}

inline int sub(int x, int y) {
  return x < y ? x - y + MOD : x - y;
}

inline int mul(int x, int y) {
  return int((i64) x * y % MOD);
}

constexpr int maxn = 1e5 + 5;

int inv[maxn];
int invFact[maxn];
int fact[maxn];

void precalc() {
  inv[0] = inv[1] = 1;
  for (int i = 2; i < maxn; ++i) {
    inv[i] = sub(MOD, mul(MOD / i, inv[MOD % i]));
  }

  invFact[0] = invFact[1] = 1;
  for (int i = 2; i < maxn; ++i) {
    invFact[i] = mul(invFact[i - 1], inv[i]);
  }

  fact[0] = 1;
  for (int i = 1; i < maxn; ++i) {
    fact[i] = mul(fact[i - 1], i);
  }
}

int comb(int n, int k) {
  if (n < k || k < 0) {
    return 0;
  }
  return mul(mul(fact[n], invFact[k]), invFact[n - k]);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  precalc();

  int n, m;
  cin >> n >> m;

  vector<vector<int>> ways(25, vector<int>(n + 1));
  for (int x = 1; x <= n; ++x) {
    ways[0][x] = 1;
    for (int i = 0; i < 25; ++i) {
      if (!ways[i][x]) {
        continue;
      }
      for (int y = 2 * x; y <= n; y += x) {
        ways[i + 1][y] = add(ways[i + 1][y], ways[i][x]);
      }
    }
  }

  int ans = mul(comb(n, m), m);
  for (int x = 1; x <= n; ++x) {
    for (int i = 0; i < min(m, 25); ++i) {
      if (ways[i][x]) {
        ans = sub(ans, mul(ways[i][x], comb(n / x - 1, m - i - 1)));
      }
    }
  }
  cout << ans << '\n';

  return 0;
}