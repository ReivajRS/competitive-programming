#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ENDL '\n'

using i64 = long long;

constexpr int MOD = 1e9 + 7;

inline int add(int x, int y) {
  return x + y < MOD ? x + y : x + y - MOD;
}

inline int sub(int x, int y) {
  return x >= y ? x - y : x - y + MOD;
}

inline int mul(int x, int y) {
  return int((i64)x * y % MOD);
}

int be(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

int inv(int a) {
  return be(a, MOD - 2);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, k;
  cin >> n >> k;

  vector<int> a(n), cnt(1000001);
  for (int& x : a) {
    cin >> x;
    ++cnt[x];
  }

  sort(a.begin(), a.end());

  int diff = 0;
  for (int i = 0; i < k; ++i) {
    diff = sub(diff, a[i]);
  }
  for (int i = n - k; i < n; ++i) {
    diff = add(diff, a[i]);
  }

  vector<vector<int>> comb(n + 1, vector<int>(n + 1));
  comb[0][0] = 1;

  for (int i = 1; i <= n; ++i) {
    comb[i][0] = comb[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      comb[i][j] = add(comb[i - 1][j], comb[i - 1][j - 1]);
    }
  }

  if (a[0] == a.back()) {
    cout << diff << ' ' << mul(mul(comb[n][k], comb[n - k][k]), inv(2)) << '\n';
    return 0;
  }

  int x = 0, y = 0;
  for (int i = k - 1; i >= 0 && a[i] == a[k - 1]; --i, ++x);
  for (int i = n - k; i < n && a[i] == a[n - k]; ++i, ++y);

  int ans = comb[cnt[a[k - 1]]][x];
  if (a[k - 1] != a[n - k]) {
    ans = mul(ans, comb[cnt[a[n - k]]][y]);
  } else {
    ans = mul(ans, comb[cnt[a[n - k]] - x][y]);
  }
  cout << diff << ' ' << ans << '\n';

  return 0;
}