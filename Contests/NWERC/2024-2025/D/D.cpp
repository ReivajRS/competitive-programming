#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
vector<int> a;
int tot = 0;
ll dp[65][600005];

ll solve(int i,int curr){
  if(i == n) return 0;
  ll &ans = dp[i][curr];
  if(ans != -1) return ans;
  ans = ((curr + a[i])*2 > tot && curr*2 <= tot);
  ans += solve(i+1,curr);
  ans += solve(i+1,curr+a[i]);
  return ans;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  memset(dp,-1,sizeof(dp));
  cin >> n;
  a.resize(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
    tot+=a[i];
  }
  sort(a.rbegin(),a.rend());
  cout << solve(0,0) << '\n';

  return 0;
}