#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i,a,b) for(int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'

constexpr ll MOD = 1000000007;

ll be(ll a,ll b,ll m = MOD){
  ll res = 1;
  a%=m;
  while(b){
    if(b&1) res= res*a%m;
    a = a*a%m;
    b>>=1;
  }
  return res;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  map<ll,ll> cnt;
  FOR(i,0,n){
    int x;
    cin >> x;
    for (int i = 2; i * i <= x; ++i) {
      if (x % i != 0) continue;
      int c = 0;
      while (x % i == 0) x /= i,c++;
      if(c&1) cnt[i]++;
    }
    if (x != 1) {
      cnt[x]++;
    }
  }
  ll ans = 1;
  for(auto &[x,c]:cnt){
    (ans*=be(x,min(c,n-c)))%=MOD;
  }
  cout << ans%MOD;

  return 0;
}