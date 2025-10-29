#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) (ll)x.size()
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)
#define ROF(i, a, b) for(ll i = (ll)a-1; i >= (ll)b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main() { __
  
  ll s,n;
  cin >>s >> n;
  vi a(n),papel;
  FOR(i,0,n){
    char c;
    cin >> a[i] >> c;
    if(c == 'y') papel.pb(a[i]);
  }

  sort(ALL(a));
  sort(ALL(papel));

  FOR(i,0,SZ(papel)){
    if(papel[i] <= i){
      cout << "no" << ENDL;
      return 0;
    }
  }

  FOR(i,0,n){
    if(i >= a[i]*s){
      cout << "no" << ENDL;
      return 0;
    }
  }
  cout << "yes" << ENDL;

  return 0;
}