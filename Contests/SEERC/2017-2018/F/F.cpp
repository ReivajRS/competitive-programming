#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) (ll) x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a-1; i >= (ll)b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main() { __

  ll n;
  cin >> n;
  vi cost(n);
  FOR(i,0,n){
    cin >> cost[i];
  }
  string s1,s2;
  cin >> s1 >> s2;
  multiset<ll,greater<ll>> apagar; 
  multiset<ll> prender;
  vi iguales;
  ll tot = 0;
  FOR(i,0,n){
    if(s1[i] == '1' && s2[i] == '1'){
      iguales.pb(cost[i]);
    }else if(s1[i] == '0' && s2[i] == '1'){
      prender.insert(cost[i]);
    }else if(s1[i] == '1' && s2[i] == '0'){
      apagar.insert(cost[i]);
    }
    if(s1[i] == '1'){
      tot+=cost[i];
    }
  }

  sort(ALL(iguales),greater<ll>());
  ll ans = LLONG_MAX;
  FOR(i,0,SZ(iguales)+1){
    ll curr = 0,aux = tot;
    if(i == 0){
      for(auto x:apagar){
        aux-=x;
        curr+=aux;
      }
      for(auto x:prender){
        aux+=x;
        curr+=aux;
      }
    }else{
      apagar.insert(iguales[i-1]);
      prender.insert(iguales[i-1]);
      for(auto x:apagar){
        aux-=x;
        curr+=aux;
      }
      for(auto x:prender){
        aux+=x;
        curr+=aux;
      }
    }
    ans = min(ans,curr);

  }

  cout << ans << ENDL;
  
  return 0;
}