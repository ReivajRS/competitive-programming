#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((ll)x.size())
#define FOR(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define ENDL '\n'

void solve(){
  ll n,f;
  cin >> n >> f;
  vector<tuple<ll,ll,ll>> a(n);
  FOR(i,0,n){
    ll l,r;
    cin >> l >> r;
    a[i] = {l,r,i};
  }
  sort(a.begin(),a.end());
  ll ans = 0;
  vector<ll> prioriza,quedan;
  FOR(i,0,n){
    auto [l,r,id] = a[i];
    ans += max(0ll,r-l);
    if(r>f){
      prioriza.push_back(id);
      ans+=max(0ll,l-f);
      f = r;
    }else{
      quedan.push_back(id);
    }
  }
  cout << ans << ENDL;
  for(auto x:prioriza){
    cout << x+1 << " ";
  }
  reverse(quedan.begin(),quedan.end());
  for(auto x:quedan){
    cout << x+1 << " ";
  }
  cout << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t;
  cin >> t;
  while(t--) solve();

  return 0;
}