#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) (int(x.size()))
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

const int INF = 1e9+5;

void solve(){
  int n;
  cin >> n;
  vector<vector<ll>> a(n,vector<ll>(n));
  FOR(i,0,n) FOR(j,0,n) cin >> a[i][j];
  int m = n/2;
  
  ll UL = INF;
  FOR(i,0,m) FOR(j,0,m) UL = min(UL,a[i][j]);

  ll U = INF;
  FOR(i,0,m) U = min(U,a[i][m]);

  ll UR = INF;
  FOR(i,0,m) FOR(j,m+1,n) UR = min(UR,a[i][j]);

  ll L = INF;
  FOR(j,0,m) L = min(L,a[m][j]);

  ll R = INF;
  FOR(j,m+1,n) R = min(R,a[m][j]);

  ll BL = INF;
  FOR(i,m+1,n) FOR(j,0,m) BL = min(BL,a[i][j]);

  ll B = INF;
  FOR(i,m+1,n) B = min(B,a[i][m]);

  ll BR = INF;
  FOR(i,m+1,n) FOR(j,m+1,n) BR = min(BR,a[i][j]);

  ll ans = a[m][m];
  ans = min(ans,U+B);
  ans = min(ans,L+R);
  ans = min(ans,UL+UR+BL+BR);
  ans = min(ans,U+BL+BR);
  ans = min(ans,B+UL+UR);
  ans = min(ans,L+UR+BR);
  ans = min(ans,R+UL+BL);
  ans = min(ans,U+R+BL);
  ans = min(ans,R+B+UL);
  ans = min(ans,B+L+UR);
  ans = min(ans,L+U+BR);

  cout << ans << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while(t--) solve();

  return 0;
}