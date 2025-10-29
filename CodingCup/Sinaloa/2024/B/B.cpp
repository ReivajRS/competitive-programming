#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<vi> a(n, vi(n));
  FOR (i, 0, n) {
    int k;
    cin >> k;
    while (k--) {
      int j;
      cin >> j;
      --j;
      a[i][j] = 1;
    }
  }
  // FOR (i, 0, n) FOR (j, 0, n) cout << a[i][j] << " \n"[j == n - 1];
  vector<vi> dp(n + 1, vi(1 << n));
  fill(ALL(dp[n]), 1);
  ROF (msk, (1 << n), 0) {
    ROF (i, n, 0) {
      dp[i][msk] += dp[i + 1][msk];
      FOR (j, i + 1, n) if (a[i][j] && !((msk >> i) & 1) && !((msk >> j) & 1)) {
        dp[i][msk] += dp[i + 1][msk | (1 << i) | (1 << j)];
      }
    }
  }
  cout << dp[0][0] << ENDL;

  return 0;
}