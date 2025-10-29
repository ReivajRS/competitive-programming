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
  
  ll n,m,k;
  cin >> n >> m >> k;
  vector<ll> a(n);
  ll total = 0;
  FOR(i,0,n){
    cin >> a[i];
    total+=a[i];
  }
  sort(ALL(a),greater<ll>());
  ll act = 0;
  FOR(i,0,m){
    act+=a[i];
  }
  if(m+k >= n){
    cout << 100 << ENDL;
    return 0;
  }

  FOR(i,m,m+k){
    act+=a[i];
  }

  cout << setprecision(6) << fixed;
  double ans = (double)act / (double)total * 100;
  cout << ans << ENDL;

  return 0;
}