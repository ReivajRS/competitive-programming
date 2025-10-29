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

template<typename T>
pair<T,vi> hungarian(const vector<vector<T>> &a){
  #define INF numeric_limits<T>::max()
  if(a.empty()) return {0,{}};
  ll n = SZ(a)+1,m = SZ(a[0])+1;
  vi p(m),ans(n-1);
  vector<T> u(n),v(m);
  FOR(i,1,n){
    p[0] = i;
    ll j0 = 0;
    vector<T> dist(m,INF);
    vi pre(m,-1);
    vector<bool> done(m+1);
    do{
      done[j0] = true;
      ll i0 = p[j0],j1;
      T delta = INF;
      FOR(j,1,m)
      if(!done[j]){
        auto cur = a[i0-1][j-1]-u[i0]-v[j];
        if(cur<dist[j]) dist[j] = cur,pre[j] = j0;
        if(dist[j]<delta) delta = dist[j],j1 = j;
      }
      FOR(j,0,m){
        if(done[j])
          u[p[j]] += delta,v[j] -= delta;
        else
          dist[j]-=delta;
      }
      j0=j1;
    } while(p[j0]);
    while(j0){
      ll j1 = pre[j0];
      p[j0] = p[j1],j0=j1;
    }
  }
  FOR(j,1,m)
  if(p[j]) ans[p[j]-1] = j-1;
  return {-v[0],ans};
};

constexpr ll INF2 = 1e8;

// y = x + a
// x + a = 0 mod b
// 998 k = 1000 - 2

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  ll n,q;
  cin >> n >> q;
  vi mn(n,1);
  vi mx(n,n);

  FOR(i,0,q){
    ll t,l,r,v;
    cin >> t >> l >> r >> v;
    l--,r--;
    if(t == 1){
      FOR(i,l,r+1){
        mn[i] = max(mn[i],v);
      }
    }else{
      FOR(i,l,r+1){
        mx[i] = min(mx[i],v);
      }
    }
  }

  vector<vi> mat(n,vi((n+1)*(n+1),INF2));

  FOR(i,0,n){
    FOR(j,mn[i],mx[i]+1){
      FOR(k,0,n){
        mat[i][j*n+k] = (k+1)*(k+1) - (k*k);
      }
    }
  }
/*
  FOR(i,0,n){
    for(auto x:mat[i]){
      cout << x << " ";
    }
    cout << ENDL;
  }
  */
  pair<ll,vi> ans = hungarian<ll>(mat);
  if(ans.first>=INF2){
    cout << -1 << ENDL;
    return 0;
  }
  cout << ans.first << ENDL;
  

  return 0;
}