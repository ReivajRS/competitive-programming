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
  
  cout << "? " << 1 << endl;
  ll dig;
  cin >> dig;
  ll aux = dig;
  ll l = 1,r = 1e18+5;
  while(l < r){
    ll mid = (l+r + 1)/2;
    cout << "? " << mid << endl;
    ll digact;
    cin >> digact;
    if(digact>dig){
      r = mid-1;
    }else{
      l = mid;
    }
  }
  // 7 8 10 -> 100 1000 10,000
  // d1 = 93, d2 = 993, d3 =9993
  // 900
  // delta2
  // 110 -> 6
  // d1 = 2
  // d2 = 18
  // d3 = 34 [16, 32]
  // [2, 4, 8]
  // [900, 9000]
  // 10 pot 3 10 pot 4
  // base pot dig = x+d1

  // base pot dig  - d1= x
  ll d1 = l;
  dig++;
  l = 1,r = 1e18+5;
  while(l < r){
    ll mid = (l+r + 1)/2;
    cout << "? " << mid << endl;
    ll digact;
    cin >> digact;
    if(digact>dig){
      r = mid-1;
    }else{
      l = mid;
    }
  }
  dig++;
  ll d2 = l;
  l = 1,r = 1e18+5;
  while(l < r){
    ll mid = (l+r+1)/2;
    cout << "? " << mid << endl;
    ll digact;
    cin >> digact;
    if(digact>dig){
      r = mid-1;
    }else{
      l = mid;
    }
    // [0, 1] digact <= dig
  }
  ll d3 = l;

  ll diff1 = d2-d1,diff2=d3-d2;
  ll base = diff2/diff1;

  ll x = pow(base,aux) - d1;
  cout << "! " << x << " " << base << endl;
  
  

  return 0;
}