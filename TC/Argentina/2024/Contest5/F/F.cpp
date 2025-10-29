#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)
#define ROF(i, a, b) for(ll i = (ll)a - 1; i >= (ll)b; i--)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n,m;
  cin >> n >> m;
  map<ll,ll> m1;
  vector<pi> a(n);
  FOR(i,0,n){
    ll x,y;
    cin >> x >> y;
    x--;
    a[i] = {y,x};
  }
  sort(a.rbegin(),a.rend());
  /*vector<pi> b(m,{0,0});
  ll cnt = 0;
  for(auto [sb,sk]:m1){
    b[cnt++] = {sk,sb};
  }
  sort(b.rbegin(),b.rend());
  vi mapeo(m);
  cnt = 0;
  FOR(i,0,m){
    if(b[i].first == 0) break;
    mapeo[b[i].second] = i;
  }*/

  vector<vi> mat(m,vi());
  FOR(i,0,n){
    mat[a[i].second].pb(a[i].first);
  }

  

  sort(ALL(mat),[&](vi i, vi j) -> bool {
    return SZ(i) > SZ(j);
  });

  vector<vi> prefix(m);
  FOR(i,0,m){
    prefix[i].assign(SZ(mat[i])+1,0);
    FOR(j,1,SZ(mat[i])+1){
      prefix[i][j] = prefix[i][j-1] + mat[i][j-1];
    }
  }



  ll ans = 0;
  
  FOR(i,1,SZ(mat[0])+1){
    ll curr = 0;
    FOR(j,0,m){
      if(SZ(mat[j]) < i) break;
      if(prefix[j][i] < 0) continue;
      curr += prefix[j][i];
    }
    ans = max(curr,ans);
  }
  cout << ans << ENDL;
  

  return 0;
}