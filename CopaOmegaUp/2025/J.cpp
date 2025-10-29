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

vector<int> leds = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int n;
int dp[105][905];

int solve(int i, int l) {
  if (i == n) {
    return l == 0;
  }
  if (l < 0) {
    return 0;
  }
  int &ans = dp[i][l];
  if (ans != -1) {
    return ans;
  }
  ans = 0;
  for (int d = 0; d <= 9; d++) {
    ans |= solve(i + 1, l - leds[d]);
  }
  return ans;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  string s;
  cin >> s;

  n = SZ(s);
  memset(dp, -1, sizeof dp);

  int l0 = 0;
  for (char c : s) {
    l0 += leds[c - '0'];
  }

  solve(0, l0);

  string ans = "";

  for (int i = 0; i < n; i++) {
    for (int d = 9; d >= 0; d--) {
      if (l0 - leds[d] >= 0 && solve(i + 1, l0 - leds[d])) {
        ans += char(d + '0');
        l0 -= leds[d];
        break;
      }
    }
  }

  cout << ans << '\n';
  
  return 0;
}