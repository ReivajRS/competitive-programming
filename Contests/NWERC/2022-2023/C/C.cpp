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

signed main() { __

  ll n;
  cin >> n;

  auto check = [&](double x) -> bool {
    ll curr = 0;
    FOR(i,1,x+1){
      curr += sqrt((x*x)- (i*i));
    }
    curr*=4;
    return curr>n;
  };

  double l=0,r=1e5;
  FOR(i,0,1000){
    double mid = (l+r)/2;
    if(check(mid)){
      r = mid;
    }else{
      l = mid;
    }
  }
  cout << setprecision(8) << fixed;
  cout << r << ENDL;

  return 0;
}