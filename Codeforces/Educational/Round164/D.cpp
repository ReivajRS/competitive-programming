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

const int MOD = 998244353;
int dp[5001][5001][2];

void solve() {
  int n;
  cin >> n;
  
  vi a(n);
  for (auto &x : a)
    cin >> x;

  sort(ALL(a));

  int s = accumulate(ALL(a), 0);
  memset(dp, -1, sizeof dp);

  auto solve = [&](auto self, int i, int x, bool f) -> int {
    if (i > n)
      return 0;
    if (f)
      return max((x + 1) / 2, a[i - 1]);
    int &ans = dp[i][x][f];
    if (ans != -1)
      return ans;
    ans = 0;
    ans = (ans % MOD + self(self, i + 1, x, 0) % MOD) % MOD;
    ans = (ans % MOD + self(self, i + 1, x + a[i], 0) % MOD) % MOD;
    ans = (ans % MOD + self(self, i + 1, x + a[i], 1) % MOD) % MOD;
    return ans;
  };

  cout << solve(solve, 0, 0, 0) << ENDL;
}

signed main() { __
  int tc;
  // cin >> tc;
  tc = 1;
  while (tc--) {
    solve();
  }
  return 0;
}