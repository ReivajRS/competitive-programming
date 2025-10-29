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

constexpr ll MOD  = 1e9+7,MAX = 2e5+5;

ll invfact[MAX];
ll inv[MAX],fact[MAX];
void precalc_inv(ll m=MOD){
  inv[0] = inv[1] = 1;
  FOR(i,2,MAX){
    inv[i] = m-(m/i)*inv[m%i]%m;
  }
}
void precalc_invfact(){
  precalc_inv();
  invfact[0] = invfact[1] = 1;
  FOR(i,2,MAX) invfact[i] = invfact[i-1] * inv[i] % MOD;
}

ll comb(ll n,ll k){
  if(n<k) return 0;
  return fact[n] * invfact[k]%MOD * invfact[n-k]%MOD;
}

vi sz;
vector<vi> g;
void dfs(ll u,ll p){
  sz[u] = 1;
  for(auto v:g[u]){
    if(v == p) continue;
    dfs(v,u);
    sz[u] += sz[v];
  }
}

ll be(ll a, ll b, ll m=MOD) {
  ll res = 1;
  a %= m;
  while (b) {
    if (b & 1) {
      res = res * a % m;
    }
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

ll modInverse(ll b){return be(b,MOD-2)%MOD;}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  fact[1] = 1;
  FOR(i,2,MAX) fact[i] = fact[i-1] * i % MOD;
  precalc_invfact();

  ll n,k;
  cin >> n >> k;
  sz.assign(n,0);
  g.assign(n,vi());
  FOR(i,1,n){
    ll u,v;
    cin >> u >> v;
    u--,v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  if(k&1){
    cout << 1 << ENDL;
    return 0;
  }
  dfs(0,-1);
  ll ans = comb(n,k);
  FOR(i,0,n){
    ans = (ans + comb(sz[i],k/2) * comb(n-sz[i],k/2) )%MOD;
  }
  ll den = comb(n,k);
  ans = ans * modInverse(den) % MOD;
  cout << ans << ENDL;


  return 0;
}