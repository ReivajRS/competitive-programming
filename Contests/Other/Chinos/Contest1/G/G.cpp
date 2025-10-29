#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'
constexpr int MAX = 2e5;
constexpr int INF = 3e8;
vi cnt0;
int n,m,k;
string s;
int dp[MAX][5];
int sig0[MAX+1];
int tam;

int solve(int pos,int faltan){
  if(faltan == -1) return 0;
  if(pos >= n) return INF;
  int &ans = dp[pos][faltan];
  if(ans !=-1) return ans;
  ans = solve(pos+1,faltan);
  if(pos+tam<=n){
    ans = min(ans,solve(sig0[pos+tam]+1,faltan-1) + cnt0[pos+tam]- cnt0[pos]);
  }
  return ans;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> m >> k;
  cin >> s;
  cnt0.assign(n+1090,0);
  FOR(i,1,n+1){
    cnt0[i] = cnt0[i-1] + (s[i-1] == '0');
  }

  int last0 = n;
  ROF(i,n,0){
    if(s[i] == '0') last0 = i;
    sig0[i] = last0;
  }
  sig0[n] = n;

  auto can = [&](int x) -> bool {
    memset(dp,-1,sizeof(dp));
    tam = x;
    //cout << solve(0,k) << ENDL;
    return solve(0,k-1) <= m;
  };

  //can(3);

  int l = 0,r = n;
  while(l<r){
    int mid = (l+r+1)/2;
    if(can(mid)) l = mid;
    else r = mid-1;
  }
  if(l==0){
    cout << -1 << ENDL;
    return 0;
  }
  cout << l << ENDL;

  return 0;
}