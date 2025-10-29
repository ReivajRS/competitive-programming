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

const int MAXN = 1e5 + 1;
int a[MAXN], b[MAXN];
ll dp[MAXN][2];

ll solve(int i, bool r) {
  if (i < 0)
    return 0;
  ll &ans = dp[i][r];
  if (ans != -1)
    return ans;
  ans = 0;
  ll val = r ? a[i] : b[i];
  ans = max(solve(i - 1, !r) + val, solve(i - 1, r));
  return ans;
}

signed main() { __
  int n;
  cin >> n;
  
  FOR (i, 0, n)
    cin >> a[i];
  FOR (i, 0, n)
    cin >> b[i];

  memset(dp, -1, sizeof dp);

  ll ans = max(solve(n - 1, 1), solve(n - 1, 0));

  cout << ans << ENDL;

  return 0;
}