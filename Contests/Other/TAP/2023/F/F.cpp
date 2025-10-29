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

inline ll dist(ll x1,ll y1,ll x2,ll y2){
  return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
}

signed main() { __

  ll n;
  cin >> n;
  ll w,l,tx,ty;
  cin >> w >> l >> tx >> ty;
  ll mn = 3e15;
  vector<pi> ptsA(n);
  FOR(i,0,n){
    ll x,y;
    cin >> x >> y;
    ptsA[i] = {x,y};
    ll d = dist(x,y,tx,ty);
    mn = min(mn,d);
  }
  ll mn2 = 3e15;
  vector<pi> ptsB(n);
  FOR(i,0,n){
    ll x,y;
    cin >> x >> y;
    ptsB[i] = {x,y};
    ll d = dist(x,y,tx,ty);
    mn2 = min(mn2,d);
  }

  ll cnt = 0;
  if(mn<mn2){
    FOR(i,0,n){
      ll d = dist(ptsA[i].first,ptsA[i].second,tx,ty);
      if(d < mn2) cnt++;
    }
    cout << "A " << cnt << ENDL;
  }else{
    FOR(i,0,n){
      ll d = dist(ptsB[i].first,ptsB[i].second,tx,ty);
      if(d < mn) cnt++;
    }
    cout << "R " << cnt << ENDL;
  }
  
  return 0;
}