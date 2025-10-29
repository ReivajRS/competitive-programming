#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((ll)x.size())
#define FOR(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)

void solve(){
  ll p,q;
  cin >> p >> q;
  ll Q = q;
  vector<ll> divs;
  for(ll i=2;i*i<=q;i++){
    if(q%i == 0){
      divs.push_back(i);
      while(q%i == 0) q/=i;
    }
  }
  if(q!=1) divs.push_back(q);
  ll ans = 0;
  FOR(i,0,SZ(divs)){
    ll curr = p;
    while(curr % Q == 0){
      curr/=divs[i];
    }
    ans = max(ans,curr);
  }
  cout << ans << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t;
  cin >> t;
  while(t--) solve();

  return 0;
}