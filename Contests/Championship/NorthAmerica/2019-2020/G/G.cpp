#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define ROF(i,a,b) for(ll i = (ll)a - 1; i >= (ll)b; i--)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n,p,q,s;
  cin >> n >> p >> q>>s;
  vi a(p);
  vi b(q);
  FOR(i,0,p) cin >> a[i];
  FOR(i,0,q) cin >> b[i];

  sort(ALL(a));
  sort(ALL(b));

  auto can = [&](ll D) -> bool {
    priority_queue<ll> pq;
    ll cnt = 0;
    ll j = 0;
    FOR(i,0,q){
      while(j<p&&a[j]-D <= b[i]){
        pq.push(-min(a[j]+D,s-a[j]));
        j++;
      }

      while(SZ(pq)){
        ll x = pq.top();
        pq.pop();
        if(-x >= b[i]){
          cnt++;
          break;
        }
      }
    }
    return cnt >=n;
  };

  ll l = 0,r = 1e9+5;
  while(l<r){
    ll mid = (l+r)/2;
    if(can(mid)){
      r = mid;
    }else{
      l = mid+1;
    }
  }
  if(l == 1e9+5) l = -1;
  cout << l << ENDL;

  return 0;
}