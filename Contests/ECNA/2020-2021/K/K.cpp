#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

vector<vi> dp;

int solve(int diff,int p){
  if(p == 1 || diff == 1) return diff;
  if(diff == 0) return 0;
  int &ans = dp[diff][p];
  if(ans!= -1) return ans;
  ans = 3e8;
  FOR(i,1,diff){
    ans = min(ans,max(solve(diff-i,p) +1 , solve(i-1,p-1)+1));
  }
  return ans;
}

signed main() { __
  
  int n,p;
  cin >> n >> p;
  dp.assign(n+5,vi(p+5,-1));
  int ans = solve(n,p); 
  cout << ans << " ";

  int mn = 3e8,mx=0;
  FOR(i,1,n){
    int aux = max(solve(n-i,p)+1,solve(i-1,p-1)+1);
    if(aux == ans){
      mn = min(mn,i);
      mx = max(mx,i);
    }
  }
  if(mn == mx){
    cout << mn << ENDL;
    return 0;
  }
  cout << mn << "-" << mx << ENDL; 

  return 0;
}