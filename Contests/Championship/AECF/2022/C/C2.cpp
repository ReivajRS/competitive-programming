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

constexpr ull INF = ULLONG_MAX / 10 - 10;

void solve(){
  string x;
  cin >> x;
  int k;
  cin >> k;
  if(k == 0){
    int n = SZ(x);

    FOR(i,0,n){
      if(x[n-i-1] != '9'){
        cout << pow(10,i) << ENDL;
        return;
      }
    }
    cout << pow(10,n) << ENDL;
    return;
  }
  while(SZ(x) <= 18) x = "0" + x;
  int n = SZ(x);
  vector<vector<vector<ull>>> dp(n, vector<vector<ull>>(k + 1, vector<ull>(2, INF)));
  dp[0][0][0] = 0;
  dp[0][0][1] = 1;
  //999
  //  15..351
  FOR (i, 1, n) {
    FOR (j, 0, k + 1) {
      int d = x[i] - '0';
      dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][0] * 10);
      if (j && d && dp[i - 1][j - 1][1] != INF)
        dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j - 1][1] * 10 + 10 - d);
      if (d != 9 && dp[i - 1][j][0] != INF) 
        dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j][0] * 10);
      if (j && dp[i - 1][j - 1][1] != INF)
        dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j - 1][1] * 10 + 9 - d);
    }
  }
  if(dp[n - 1][k][0] >= INF) dp[n - 1][k][0] = -1;
  cout << dp[n - 1][k][0] << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while(t--) solve();

  return 0;
}