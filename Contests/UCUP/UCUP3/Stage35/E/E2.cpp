#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

constexpr ll MOD = 998244353;

ll be(ll a,ll b,ll m = MOD){
  ll res = 1;
  a%=m;
  while(b){
    if(b&1) res = res * a%m;
    a = a*a%m;
    b>>=1;
  }
  return res;
}

void solve(){
  ll a,b;
  cin >> a >> b;
  int c = 0;
  if((a+b)&1 ) {
    cout << 2 << '\n';
    return;
  }
  if(a>b) swap(a,b);
  while(a!=b && c < 500){
    ll x = a;
    a += x;
    b -= x;
    if (a > b) {
      swap(a, b);
    }
    ++c;
  }
  if(c == 500){
    cout << 2 << '\n';
    return;
  }
  ll ans = (2 - be(be(2,c),MOD-2) + MOD) % MOD;
  cout << ans << '\n';

}

/*
1 + 1/2(1+1/2(....))
1 + 1/2+1/4+1/8
1 + 2**c -1 / 2**c
15/8
*/

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while(t--) solve();

  return 0;
}