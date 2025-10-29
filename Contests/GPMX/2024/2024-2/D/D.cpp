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

const int MOD = 1e9 + 7, offset = 800 * 9;
int dp[801][800 * 9 * 2 + 1];

int solve(int i, int dif) {
  if (i == 0)
    return dif == 0;
  int &ans = dp[i][dif + offset];
  if (ans != -1)
    return ans;
  ans = 0;
  FOR (d, 1, 10) {
    int ways = 10 - d;
    ans += (1ll * solve(i - 1, dif + d) * ways) % MOD;
    ans %= MOD;
    ans += (1ll * solve(i - 1, dif - d) * ways) % MOD;
    ans %= MOD;
  }
  return ans;
}

signed main() { __
  memset(dp, -1, sizeof dp);

  int q;
  cin >> q;

  while (q--) {
    int x;
    cin >> x;
    int ans = 0;
    FOR (d, 1, 10) {
      int ways = 9 - d;
      ans += (1ll * solve(x - 1, d) * ways) % MOD;
      ans %= MOD;
      ans += (1ll * solve(x - 1, -d) * ways) % MOD;
      ans %= MOD;
    }
    cout << ans << ENDL;
  }

  return 0;
}