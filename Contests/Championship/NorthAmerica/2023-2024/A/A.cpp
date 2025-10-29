#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i,a,b) for(int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vi a(n),b(n);
  int sum = 0;
  FOR(i,0,n){
    cin >> a[i] >> b[i];
    sum+=a[i];
  }
  vi dp(sum+5,0);
  FOR(i,0,n){
    vi dp2(sum+5,0);
    FOR(j,0,sum+1){
      dp2[j] = dp[j] + b[i];
      if(j>=a[i]){
        dp2[j] = min(dp2[j],dp[j-a[i]]);
      }
    }
    swap(dp,dp2);
  }
  int ans = 1e9+5;
  FOR(i,0,sum+1){
    ans = min(ans,max(i,dp[i]));
  }
  cout << ans << ENDL;

  return 0;
}