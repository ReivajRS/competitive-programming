#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main() { __
  
  ll n,c;
  cin >> n >> c;
  vector<ll> a(n);
  FOR(i,0,n){
    cin >> a[i];
  }
  ll curr = 0;
  ll quedan = 0;
  ll ans = 3e15;
  ll ans2 = 3e15;
  FOR(i,0,n){
    curr = quedan + a[i];
    ll tiempo = (curr + c)/c;
    //cout << tiempo << " ";
    if(i+tiempo <= n){
      if(tiempo < ans2){
        ans = i;
        ans2 = tiempo;
        if(tiempo == 1){
          cout << ans << ENDL;
          return 0;
        }
      }
    }
    quedan = max(0LL,curr-c);
  }
  if(ans == (ll)3e15){
    cout << "impossible" << ENDL;
    return 0;
  }
  cout << ans << ENDL;

  return 0;
}