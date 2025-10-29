#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
#define ld long double

#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'

vector<vector<ld>> dp;
vector<ld> prefCuad,pref;
int N;
// [i,j) O(1)
ld calculo(int i,int j){
  ld ans = 0;
  ans += prefCuad[j]-prefCuad[i];
  ld xp = (pref[j]-pref[i]) / ((ld)(j-i));
  ans += (xp*xp) * (j-i);
  ans += -2*xp * (pref[j]-pref[i]);

  return ans;
}

ld solve(int i,int antenas){
  if(antenas == 1){
    return calculo(i,N);
  }
  if(i == N && antenas) return 3e15;
  ld &ans = dp[i][antenas];
  if(ans >= 0) return ans;
  ans = 3e15;
  FOR(j,i+1,N+1){
    ans = min(ans,calculo(i,j)+ solve(j,antenas-1));
  }
  return ans;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n,m,k,s;
  cin >> n >> m >> k >> s;
  N = n+m;
  dp.assign(N+5,vector<ld>(k+5,-1));
  vector<ld> pts(n+m);
  FOR(i,0,n+m){
    cin >> pts[i];
  }
  sort(ALL(pts));
  pref.assign(n+m+1,0);
  prefCuad.assign(n+m+1,0);
  FOR(i,1,n+m+1){
    pref[i] = pref[i-1] + pts[i-1];
    prefCuad[i] = prefCuad[i-1] + (pts[i-1]*pts[i-1]);
  }

  ld yp = s/2.0;
  ld aux = N*1.0 * (yp*yp);
  ld ans = solve(0,k)+aux;
  cout << setprecision(9) << fixed;
  cout << ans << ENDL;

  return 0;
}