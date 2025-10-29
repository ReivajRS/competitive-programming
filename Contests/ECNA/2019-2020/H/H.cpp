#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) (ll)x.size()
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)
#define ROF(i, a, b) for(ll i = (ll)a-1; i >= b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main() { __
  

  ll a,b,c,d,e,f,g;
  cin >> a >> b >> c >> d >> e >> f >> g;
  vi cajas;
  ll mx = min(a/2,b/2);
  FOR(i,1,mx + 1){
    cajas.pb((a-2*i) * (b-2*i) * i);
  }
  sort(cajas.rbegin(),cajas.rend());
  //cout << cajas[0] << " " << cajas[1] << " " << cajas[2] << ENDL;
  //cout << 22457%cajas[0] << " " << 22457%cajas[1] << " " << 22457%cajas[2] << ENDL;

  f-=c;
  g-=c;
  for(ll i=(f+cajas[0] - 1)/(cajas[0]); i*cajas[0] <= g;i++){
    ll libros = i*cajas[0] + c;
    if(libros%cajas[1] == d && libros%cajas[2] == e){
      cout << libros << ENDL;
      return 0;
    }
  }

  return 0;
}