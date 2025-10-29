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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n,r;
  cin >> n >> r;
  vi a(n);
  vector<double> ans(n);
  FOR(i,0,n) cin >> a[i];
  FOR(i,0,n){
    ans[i] = r;
    FOR(j,0,i){
      double dist = (a[i]-a[j])*(a[i]-a[j]);
      double distrad = (r+r)*(r+r);
      if(dist<=distrad){
        ans[i] = max(ans[i],ans[j]+sqrt(distrad-dist));
      }
    }
  }
  cout << setprecision(9) << fixed;
  FOR(i,0,n){
    cout << ans[i] << " ";
  }
  return 0;
}