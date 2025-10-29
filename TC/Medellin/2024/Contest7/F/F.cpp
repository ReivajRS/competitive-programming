#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'

constexpr int MAX = 5e5+5,MOD = 1e9+7;

ll inv[MAX];
ll fact[MAX];
void precalc_inv(int m =MOD){
  inv[0] = inv[1] = 1;
  FOR(i,2,MAX){
    inv[i] = m-(m/i)*inv[m%i]%m;
  }
}

ll invfact[MAX];
void precalc(){
  fact[1] = 1;
  FOR(i,2,MAX){
    fact[i] = i*fact[i-1] %MOD;
  }
  precalc_inv();
  invfact[0] = invfact[1] = 1;
  for(int i=2;i<MAX;i++) 
    invfact[i] = invfact[i-1]*inv[i]%MOD;
}

ll comb(int n,int k){
  if(n<k) return 0;
  return fact[n]*invfact[k] % MOD * invfact[n-k]%MOD;
}


signed main() {
  cin.tie(0)->sync_with_stdio(0);

  precalc();

  int n;
  cin >> n;
  ll ans = 1;
  FOR(i,2,n+1){
    //cout << comb(i,2) << ENDL;
    ans*= comb(i,2);
    ans%=MOD;
  }
  cout << ans << ENDL;

  //cout << solve(10) << ENDL;
  
  return 0;
}