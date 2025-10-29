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
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

inline const ll sum(ll x){return x*(x+1)/2;}

signed main() { __

  string s;
  cin >> s;
  ll aux;
  FOR(i,0,SZ(s)){
    if(s[i] == '/'){
      aux = i;
      break;
    }
  }

  ll a = stoll(s.substr(0,aux));
  ll b = stoll(s.substr(aux+1));

  if(a < b-1){
    cout << "impossible" << ENDL;
    return 0;
  }

  ll num = a, den = b;
  while(sum(den-1) < num){
    num += a;
    den += b;
    if(den> (ll)1e6){
      cout << "impossible" << ENDL;
      return 0;
    }
  }
  ll l = 0;
  FOR(i,0,den+5){
    if(sum(i)<=num){
      int sobran = (den-1)-i;
      if(sobran< num-sum(i))
        l = i;

    }else{
      break;
    }
  }

  
  ll n = den;
  ll m = den-1;

  cout << n << " " << m << ENDL;
  FOR(i,1,l+1){
    cout << i << " " << i+1 << ENDL;
  }
  ll falta = num-sum(l);
  ll sobran = m-l;
  FOR(i,0,sobran-1){
    cout << 1 <<" " << l+2+i << ENDL;
  }
  ll aux2 = falta - (sobran-1);
  if(sobran > 0)
    cout << aux2 << " " << n << ENDL;
  
  return 0;
}