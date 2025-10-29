#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((ll)x.size())
#define FOR(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)

vector<vector<ll>> dp[2];
vector<vector<ll>> a;
ll n,m;
ll solve(ll i,ll j,ll izq){
  if(i == n-1 && j == m-1) return 0;
  ll &ans = dp[izq][i][j];
  if(ans!=-1) return ans;
  ans = 0;
  if(izq && j>0  && i < n-2){
    ans = max(ans,solve(i+2,j-1,0) + a[i+1][j] + a[i+1][j-1]+a[i+2][j-1]);
  }
  if(izq && i<n-1 && j<m-1){
    ans = max(ans,solve(i+1,j,0) + a[i][j+1] + a[i+1][j]);
  }
  if(izq && i<n-1 && j>0){
    ans = max(ans,solve(i+1,j,0) + a[i+1][j]+a[i+1][j-1]);
  }

  if(i<n-1){
    ans = max(ans,solve(i+1,j,izq)+a[i+1][j]);
  }
  if(j<m-1)
    ans = max(ans,solve(i,j+1,izq)+a[i][j+1]);

  return ans;
}

void solve2(){
  cin >> n >> m;
  a.assign(n,vector<ll>(m));
  FOR(i,0,n) FOR(j,0,m) cin >> a[i][j];
  dp[0].assign(n,vector<ll>(m,-1));
  dp[1].assign(n,vector<ll>(m,-1));
  cout << solve(0,0,1) + a[0][0] << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t;
  cin >> t;
  while(t--) solve2();

  return 0;
}