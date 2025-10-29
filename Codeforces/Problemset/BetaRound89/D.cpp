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

constexpr int mod = 1e8;
int n1, n2, k1, k2;
int dp[101][101][11][11];

int solve(int i, int j, int ci, int cj) {
  if (i + j == n1 + n2) return 1;
  int &ans = dp[i][j][ci][cj];
  if (ans != -1) return ans;
  ans = 0;
  if (ci < k1 && i + 1 <= n1) ans = (ans + solve(i + 1, j, ci + 1, 0)) % mod;
  if (cj < k2 && j + 1 <= n2) ans = (ans + solve(i, j + 1, 0, cj + 1)) % mod;
  return ans;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  cin >> n1 >> n2 >> k1 >> k2;

  memset(dp, -1, sizeof dp);

  cout << solve(0, 0, 0, 0) << ENDL;
  
  return 0;
}