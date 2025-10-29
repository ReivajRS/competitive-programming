#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main() { __
  int n;
  cin >> n;

  vector<vi> dp(n + 1, vi(n + 1, 1e9 + 7));

  vi a(n);
  FOR (i, 0, n) {
    cin >> a[i];
  }

  FOR (i, 0, n) {
    FOR (j, 0, n) {
      dp[i][j] = 1e9 + 7;
    }
  }

  ROF(i, n, 0) {
    FOR (j, i + 1, n) {
      dp[i][j] = min({abs(a[i] - a[j]), dp[i][j - 1], dp[i + 1][j]});
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << dp[l - 1][r - 1] << ENDL;
  }

  return 0;
}