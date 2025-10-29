#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i,a,b) for(int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'

using i128 = __int128_t;

constexpr i128 INF = 1e37;

void print(i128 x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}

void solve(){
  string x;
  cin >> x;
  int k;
  cin >> k;
  if(k == 0){
    int n = SZ(x);
    i128 ans = 1;
    ROF (i, n, 0) {
      if (x[i] != '9') break;
      ans *= 10;
    }
    print(ans);
    cout << "\n";
    return;
  }
  FOR (i, 0, 40) x = "0" + x;
  int n = SZ(x);
  vector<vector<vector<i128>>> dp(n, vector<vector<i128>>(k + 1, vector<i128>(2, INF)));
  dp[0][0][0] = 0;
  dp[0][0][1] = 1;
  //999
  //  15..351
  FOR (i, 1, n) {
    FOR (j, 0, k + 1) {
      int d = x[i] - '0';
      dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][0] * 10);
      if (j && d)
        dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j - 1][1] * 10 + 10 - d);
      if (d != 9) 
        dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j][0] * 10);
      if (j)
        dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j - 1][1] * 10 + 9 - d);
    }
  }
  print(dp[n - 1][k][0]);
  cout << "\n";
}

signed main() {
  int t;
  cin >> t;
  while(t--) solve();

  return 0;
}