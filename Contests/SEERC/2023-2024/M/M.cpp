#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;


#define FOR(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define ENDL '\n'


void solve(){
  ll n;
  cin >> n;
  vi a(n);
  ll mn = 1e9+5,mni = -1,mx = -1,mxi = -1;
  FOR(i,0,n) {
    cin >> a[i];
    if(a[i]<mn){
      mn = a[i];
      mni = i;
    }
    if(a[i]>mx){
      mx = a[i];
      mxi = i;
    }
  }

  auto check = [&](ll x) -> bool {
    // Subir al mn
    //Buscar l
    ll l = 0;
    for(ll i=mni-1;i>=0;i--){
      if(a[i]-mn > x){
        l = i+1;
        break;
      }
    }
    // Buscar la r
    ll r = n-1;
    for(ll i=mni+1;i<n;i++){
      if(a[i]-mn > x){
        r = i-1;
        break;
      }
    }

    ll mnx=1e9+5,mxx = -1;
    FOR(i,0,l){
      mnx = min(mnx,a[i]);
      mxx = max(mxx,a[i]);
    }
    FOR(i,r+1,n){
      mnx = min(mnx,a[i]);
      mxx = max(mxx,a[i]);
    }
    if(mxx-mnx <= x) return true;

    //Bajar mx

    //Buscar l
    l = 0;
    for(ll i=mxi-1;i>=0;i--){
      if(mx-a[i] > x){
        l = i+1;
        break;
      }
    }
    // Buscar la r
    r = n-1;
    for(ll i=mxi+1;i<n;i++){
      if(mx-a[i] > x){
        r = i-1;
        break;
      }
    }

    mnx=1e9+5,mxx = -1;
    FOR(i,0,l){
      mnx = min(mnx,a[i]);
      mxx = max(mxx,a[i]);
    }
    FOR(i,r+1,n){
      mnx = min(mnx,a[i]);
      mxx = max(mxx,a[i]);
    }
    if(mxx-mnx <= x) return true;

    return false;
  };

  ll l = 0,r = 1e9+5;
  while(l<r){
    ll mid = (l+r)/2;
    if(check(mid)) r=mid;
    else l= mid+1;
  }
  cout << l << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t;
  cin >> t;
  while(t--) solve();

  return 0;
}