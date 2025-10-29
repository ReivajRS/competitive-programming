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

signed main() { __

  ll n,m;
  cin >> n >> m;
  vi a(n);
  FOR(i,0,n) cin >> a[i];
  vi b;
  ll aux = 3e15;
  FOR(i,0,m){
    ll x;
    cin >> x;
    if(x< aux){
      aux = x;
      b.pb(-x);
    }
  }

  FOR(i,0,n){
    while(true){
      ll pos = lower_bound(b.begin(),b.end(),-a[i]) - b.begin();
      if(pos == SZ(b)) break; 
      a[i] -= a[i]/(-b[pos]) * (-b[pos]);
    }
    cout << a[i] << " ";
  }


  
  return 0;
}