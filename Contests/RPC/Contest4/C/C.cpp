#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i,a,b) for (int i = (int)a;i<(int)b;++i)

signed main() {

  int n;
  cin >> n;
  vi a(n);
  FOR(i,0,n){
    cin >> a[i];
  }

  a.pb(-1);

  int ans = 0;
  FOR(i,0,n){
    FOR(j,i+1,n+1){
      if(a[j-1] >= a[j]){
        ans = max(ans,j-i);
        break;
      }
    }
  }
  cout << ans << '\n';
  
  return 0;
}