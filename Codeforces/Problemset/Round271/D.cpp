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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t, k;
  cin >> t >> k;

  const int MOD = 1e9 + 7, MAXN = 1e5 + 1;
  vi dp(MAXN + 1, 0);
  dp[0] = 1;

  FOR (i, 0, MAXN) {
    if (i + 1 < MAXN) {
      dp[i + 1] += dp[i];
      dp[i + 1] %= MOD;
    }
    if (i + k < MAXN) {
      dp[i + k] += dp[i];
      dp[i + 1] %= MOD;
    }
  }

  vi pref(MAXN + 1, 0);
  FOR (i, 1, MAXN) {
    pref[i] = pref[i - 1] + dp[i];
    pref[i] %= MOD;
  }

  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << (pref[b] - pref[a - 1] + MOD) % MOD << ENDL;
  }
  
  return 0;
}