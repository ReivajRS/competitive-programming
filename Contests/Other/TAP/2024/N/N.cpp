#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i,a,b) for(int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<ll> a(n);
  FOR(i,0,n)cin>>a[i];
  if (n == 1){
    cout << 0 << ENDL;
    return 0;
  }
  sort(a.rbegin(),a.rend());
  ll x=a[0],y=a[n-1],z=a[0];
  ll ans=x*x+y*y+z*z-x*y-x*z-y*z;
  cout << ans << '\n'; 
  return 0;
}