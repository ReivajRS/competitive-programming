#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define ROF(i,a,b) for(ll i = (ll)a-1; i >= (ll)b; i--)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n,c;
  cin >> n >> c;
  ll tot = 0;
  vector<pi> a(n);
  FOR(i,0,n){
    cin >> a[i].second >> a[i].first;
  }
  sort(a.rbegin(),a.rend());

  auto can = [&](ll x) -> bool {
    ll curr = 0;
    ll res = 0,f=0;
    for(auto [d,t] : a){
      ll dias = min(x+1,(t+d-1)/d);
      curr = max(0ll,t-d*dias);
      res += curr+dias;
      f += (curr != 0 ? curr+1:0);
    }
    if(res > (x+1)*c) return false;
    return f<=c;
  };

  ll l = 0,r = (1e18+5)/c;
  while(l < r){
    ll mid = (l+r)/2;
    if(can(mid)){
      r = mid;
    }else{
      l = mid+1;
    }
  }
  cout << l << ENDL;
  

  return 0;
}