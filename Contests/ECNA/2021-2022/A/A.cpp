#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) begin(x),end(x)
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i,a,b) for(int i = (int)a - 1; i>= (int)b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);


signed main() {__

  int n;
  cin >> n;
  vi dp(n+5,0);
  FOR(i,1,n+1){
    dp[i] =i;
    FOR(j,0,i){
      dp[i] =min(dp[i],dp[i-j] + dp[j]); 
    }
    for(int j = 2;j*j<=i ;j++){
      if(i%j == 0){
        dp[i] = min(dp[i],dp[j]+dp[i/j]);
      }
    }
    string aux = to_string(i);
    FOR(j,1,SZ(aux)){
      string s1 = aux.substr(0,j), s2 = aux.substr(j);
      if(s2[0] == '0')continue;
      dp[i] = min(dp[i],dp[stoi(s1)] + dp[stoi(s2)]);
    }
  }
  cout << dp[n] << ENDL;

  return 0;
}