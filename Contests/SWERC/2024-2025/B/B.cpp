#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;
using pi = pair<ll,ll>;
#define SZ(x) ((ll)x.size())
#define FOR(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)

ll n,k;
vi pref,pref2;
vector<pi> a;
vector<vi> dp,sig;

ll calc(ll l,ll r){
  ll x = a[r-1].first;
  return (r-l)*x*x - 2*x*(pref[r]-pref[l]) + (pref2[r]-pref2[l]);
}
// l,r)
ll solve(ll pos,ll used){
  if(used > k) return 1e18;
  if(pos == n)return 0;
  ll &ans = dp[pos][used];
  if(ans != -1) return ans;
  ans = 1e18;
  FOR(i,pos+1,n +1){
    ll opc = solve(i,used+1) +calc(pos,i );
    if(opc < ans){
      ans = opc;
      sig[pos][used] = i;
    }
  }
  return ans;
}


signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> k;
  dp.assign(n,vi(k+1,-1));
  sig.assign(n,vi(k+1,-1));
  a.resize(n);
  pref.assign(n+1,0);
  pref2.assign(n+1,0);
  FOR(i,0,n){
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(),a.end());
  FOR(i,0,n){
    pref[i+1] = pref[i] + a[i].first;
    pref2[i+1] = pref2[i] + a[i].first*a[i].first;
  } 
  solve(0,0);
  vi ans(n,0);
  ll used = 0,curr = 0;
  while(curr < n){
    ll nxt = sig[curr][used];
    FOR(i,curr,nxt){
      ans[a[i].second] = a[nxt-1].first;
    }
    curr = nxt;
    used++;
  }

  for(auto x:ans) cout << x << " ";
  cout << '\n';



  return 0;
}