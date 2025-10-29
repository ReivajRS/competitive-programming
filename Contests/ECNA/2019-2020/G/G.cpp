#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) (ll)x.size()
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)
#define ROF(i, a, b) for(ll i = (ll)a-1; i >= b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main() { __
  
  ll n,m,A,c,x0;
  cin >> n >> m >> A >> c >> x0;
  vi a(n);
  a[0] = (A*x0 + c) % m;
  FOR(i,1,n){
    a[i] = (A*a[i-1]+c)%m;
  }

  ll ans = 0;
  FOR(i,0,n){
    ll l=0,r=n-1;
    while(l<=r){
      ll mid = (l+r)/2;
      if(a[mid] == a[i]){
        ans++;
        break;
      }
      if(a[mid]<a[i]) l=mid+1;
      else r = mid-1;
    }
  }
  cout << ans << ENDL;


  return 0;
}
