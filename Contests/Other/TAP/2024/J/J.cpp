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

  ll n,X;
  cin >> n >> X;
  map<ll,ll> mp;
  FOR(i,0,n){
    ll x;
    cin >> x;
    mp[x]++;
  }
  
  vector<pi> aa;
  for(auto [x,cnt]:mp){
    aa.pb({cnt,x});
  }
  sort(ALL(aa));
  queue<pi> q1;
  for(auto x:aa) q1.push(x);
  queue<ll> q2;
  while(SZ(q1)){
    auto [cnt,x] = q1.front();
    q1.pop();
    q2.push(x);
    cnt--;
    if(cnt>0){
      q1.push({cnt,x});
    }
  }

  ll x = q2.front();
  q2.pop();
  vi ans;
  ans.pb(x);
  FOR(i,1,n){
    ll mx = SZ(q2);
    ll cnt = 0;
    while(true){
      ll y = q2.front();
      q2.pop();
      if(cnt++ >= mx){
        cout << "*" << ENDL;
        return 0;
      }
      if(x+y == X){
        q2.push(y);
      }else{
        ans.pb(y);
        x = y;
        break;
      }
    }
  }
  FOR(i,0,n){
    cout << ans[i] << " \n"[i == n-1];
  }

  return 0;
}