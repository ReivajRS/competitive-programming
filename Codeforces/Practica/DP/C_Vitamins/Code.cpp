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

const int MAXN = 1e3 + 1;
int a[MAXN];
string b[MAXN];
int dp[MAXN][8];

int solve(int i, int mask) {
  if (mask == 7)
    return 0;
  if (i < 0)
    return mask == 7 ? 0 : 1e9;
  int &ans = dp[i][mask];
  if (ans != -1)
    return ans;
  ans = 1e9;
  int nmask = mask;
  for (char c : b[i])
    nmask |= (1 << (c - 'A'));
  ans = min(solve(i - 1, mask), solve(i - 1, nmask) + a[i]);
  return ans;
}

signed main() { __
  int n;
  cin >> n;
  FOR (i, 0, n) {
    cin >> a[i] >> b[i];
  }
  memset(dp, -1, sizeof dp);
  int ans = solve(n - 1, 0);
  if (ans == 1e9)
    ans = -1;
  cout << ans << ENDL;
  return 0;
}