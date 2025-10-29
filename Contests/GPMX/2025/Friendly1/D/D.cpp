#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n,w;
  cin >> n>>w;
  vector<ll> p(n+1),cap(n+1),water(n+1);
  FOR(i,1,n+1){
    cin >> p[i] >> cap[i] >> water[i];
  }
  vector<ll> dp(n+1,0);
  dp[0] = w;
  FOR(i,1,n+1){
    dp[i] = cap[i] - water[i] + max(0ll,dp[p[i]] - cap[i]);
  }
  cout << *min_element(dp.begin(),dp.end()) << '\n';
  
  return 0;
}