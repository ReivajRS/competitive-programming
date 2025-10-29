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

int N, K;
string s;
int dp[501][501][501];
const int INF = 1e9;

int solve(int l, int r, int k) {
  if (r < 0 || l >= N || k < 0)
    return INF;
  if (k == 0 || (l == r && k == 1))
    return 0;
  if (l >= r)
    return INF;
  int &ans = dp[l][r][k];
  if (ans != -1)
    return ans;
  ans = INF;
  int dif = s[l] != s[r];
  ans = min({solve(l + 1, r, k), solve(l, r - 1, k), solve(l + 1, r - 1, k - 2) + dif});
  return ans;
}

signed main() { __
  cin >> N >> K >> s;
  memset(dp, -1, sizeof dp);
  cout << solve(0, N - 1, K);
  return 0;
}