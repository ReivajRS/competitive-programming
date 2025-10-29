#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
#define SZ(x) ((int)(x).size())

string l, r;
int dp[10][2][2][10][10];
int f(int i, int tl, int tr, int cl, int cr) {
  if (i == SZ(l)) {
    return cl + cr;
  }
  int &ans = dp[i][tl][tr][cl][cr];
  if (ans != -1) {
    return ans;
  }
  ans = 1e9;
  int lb = tl ? l[i] - '0' : 0;
  int rb = tr ? r[i] - '0' : 9;
  for (int d = lb; d <= rb; d++) {
    ans = min(ans, f(i + 1, tl & (d == lb), tr & (d == rb), cl + (d == l[i] - '0'), cr + (d == r[i] - '0')));
  }
  return ans;
}

void solve() {
  cin >> l >> r;
  memset(dp, -1, sizeof dp);
  cout << f(0, 1, 1, 0, 0) << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  
  return 0;
}