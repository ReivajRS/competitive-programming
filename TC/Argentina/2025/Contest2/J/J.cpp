#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<int> a(n),b(n);
  ll tot = 0;
  FOR(i,0,n) {cin >> a[i] >> b[i]; tot+=b[i];}
  int mx = 10005;
  vector<vector<int>> prev(n + 1, vector<int>(mx, -1e9));
  prev[0][0] = 0;
  FOR(i,0,n){
    vector<vector<int>> curr(n + 1, vector<int>(mx,-1e9));
    FOR(k, 0, i +1) {
      FOR(c, 0, mx) {
        curr[k][c] = max(curr[k][c], prev[k][c]);
        if (c + a[i] < mx) {
          curr[k + 1][c + a[i]] = max(curr[k + 1][c + a[i]], prev[k][c] + b[i]);
        }
      }
    }
    prev = curr;
  }
  vector<double> ans(n);
  FOR(k,1,n+1){
    FOR(c,0,mx){
      double resto = (tot-prev[k][c])/2.0;
      ans[k-1] = max(ans[k-1], min(1.0*c,prev[k][c]+resto));
    }
  }
  cout << setprecision(12) << fixed;
  for(auto x:ans) cout << x << " ";


  return 0;
}