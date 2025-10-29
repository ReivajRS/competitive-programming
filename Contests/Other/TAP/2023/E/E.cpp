#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) (ll) x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define ROF(i, a, b) for (ll i = (ll)b - 1; i >= (ll)a; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

ll solve(ll d,ll a,ll s,ll l,ll r){
  vector<ll> prefix;
  prefix.pb(0);
  for(ll i = a+d;i<=r;i+=d){
    prefix.pb(prefix.back()+i);
  }
  ll ans = 0;
  ll aux = 0;
  if(binary_search(ALL(prefix),s-a-aux)){
      ans++;
  }
  for(ll i=a-d;i>=l;i-=d){
    aux+=i;
    if(binary_search(ALL(prefix),s-a-aux)){
      ans++;
    }
  }
  return ans;
}

signed main() { __

  ll a,s,l,r;
  cin >> a >> s >> l >> r;
  if(a == s){
    cout << 1 << ENDL;
    return 0;
  }
  ll d = r-l;
  ll ans = 0;
  FOR(i,1,d+1){
    ans += solve(i,a,s,l,r);
  }
  cout << ans << ENDL;
  return 0;
}