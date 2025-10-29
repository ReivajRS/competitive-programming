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
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

constexpr int MAXN = 101;
int a[MAXN];
int dp[MAXN][3];

int solve(int i, int last) {
  if (i < 0)
    return 0;
  int &ans = dp[i][last];
  if (ans != -1)
    return ans;
  ans = 1e9;
  ans = solve(i - 1, 0) + 1;
  if (last != 1 && (a[i] & (1 << 0)))
    ans = min(ans, solve(i -  1, 1));
  if (last != 2 && (a[i] & (1 << 1)))
    ans = min(ans, solve(i - 1, 2));
  return ans;
}

signed main() { __
  int n;
  cin >> n;

  FOR (i, 0, n) {
    cin >> a[i];
  }
  
  memset(dp, -1, sizeof dp);
  int ans = solve(n - 1, 0);

  cout << ans << ENDL;

  return 0;
}