#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i,a,b) for (int i = (int)a;i<(int)b;++i)

constexpr ll MOD = 1e9+7;

ll dp[101][101][101][4];

signed main() {

  int a,b,c;
  cin >> a >> b >> c;
  
  memset(dp,-1,sizeof(dp));

  auto solve = [&](auto self,int a,int b,int c,int ant) -> ll {
    if(a < 0 || b < 0 || c < 0) return 0;
    if(a == 0 && b == 0 && c == 0) return 1;

    ll &ans = dp[a][b][c][ant];
    if(ans != -1) return ans;

    ans = 0;
    if(ant == 0){
      ans += self(self,a,b-1,c,1);
      ans%=MOD;
      ans += self(self,a,b,c-1,2);
      ans%=MOD;
    }else if(ant == 1){
      ans += self(self,a-1,b,c,0);
      ans%=MOD;
      ans += self(self,a,b,c-1,2);
      ans%=MOD;
    }else if(ant == 2){
      ans += self(self,a-1,b,c,0);
      ans%=MOD;
      ans += self(self,a,b-1,c,1);
      ans%=MOD;
    }
    ans%=MOD;
    return ans;
  };

  ll ans = solve(solve,a-1,b,c,0);
  ans += solve(solve,a,b-1,c,1);
  ans%=MOD;
  ans += solve(solve,a,b,c-1,2);
  ans%=MOD;
  cout << ans << "\n";
  
  return 0;
}