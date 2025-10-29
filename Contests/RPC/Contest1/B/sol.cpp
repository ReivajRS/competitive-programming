#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = a - 1; i >= b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

int c,n;
vi arr;
int dp[1005][1005][2];

int solve(int remaing,int pos,int cd){
  if(remaing < 0) return -3e8;
  if(pos == n) return 0;
  int &ans = dp[remaing][pos][cd];
  if(ans != -1)return ans;
  ans = 0;
  if(cd == 0){
    ans = solve(c,pos,1); 
  }
  ans = max(ans, solve(remaing-arr[pos],pos+1,cd) + arr[pos]);

  return ans;
}

signed main() { __
  memset(dp,-1,sizeof(dp));

  cin >> c >> n;
  arr.resize(n);
  FOR(i,0,n){
    cin >> arr[i];
  }

  int ans = solve(c,0,0);
  cout << ans << ENDL;
  FOR(i,0,c+1){
    int curr = c-i;
    FOR(j,0,n){
      if(dp[i][j][0] + curr == ans){
        cout << curr << " " << dp[i][j][0];
        return 0;
      }
    }
    
  }

  return 0;
}