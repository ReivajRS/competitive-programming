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

struct Nodo{
  ll last,cnt,total;
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n,m;
  cin >> n >> m;
  map<ll,ll> mp;
  vector<vi> mat(n,vi(m));
  FOR(i,0,n){
    FOR(j,0,m){
      cin >> mat[i][j];
    }
  }

  unordered_map<ll,Nodo> mapa;


  ll ans = 0;
  FOR(i,0,n){
    FOR(j,0,m){
      if(mapa.count(mat[i][j])){
        Nodo &nodo = mapa[mat[i][j]];
        if(nodo.last != i){
          nodo.total = nodo.total+nodo.cnt*(abs(i-nodo.last));  
        }
        ans+=nodo.total;
        nodo.last = i;
        nodo.cnt++;
      }else{
        Nodo nd = {i,1,0};
        mapa[mat[i][j]] = nd;
      }
    }
  }

  mapa.clear();

  ROF(i,n,0){
    FOR(j,0,m){
      if(mapa.count(mat[i][j])){
        Nodo &nodo = mapa[mat[i][j]];
        if(nodo.last != i){
          nodo.total = nodo.total+nodo.cnt*(abs(i-nodo.last));  
        }
        ans+=nodo.total;
        nodo.last = i;
        nodo.cnt++;
      }else{
        Nodo nd = {i,1,0};
        mapa[mat[i][j]] = nd;
      }
    }
  }

  mapa.clear();
  
  FOR(j,0,m){
      FOR(i,0,n){
      if(mapa.count(mat[i][j])){
        Nodo &nodo = mapa[mat[i][j]];
        if(nodo.last != j){
          nodo.total = nodo.total+nodo.cnt*(abs(j-nodo.last));  
        }
        ans+=nodo.total;
        nodo.last = j;
        nodo.cnt++;
      }else{
        Nodo nd = {j,1,0};
        mapa[mat[i][j]] = nd;
      }
    }
  }

  mapa.clear();

  ROF(j,m,0){
      FOR(i,0,n){
      if(mapa.count(mat[i][j])){
        Nodo &nodo = mapa[mat[i][j]];
        if(nodo.last != j){
          nodo.total = nodo.total+nodo.cnt*(abs(j-nodo.last));  
        }
        ans+=nodo.total;
        nodo.last = j;
        nodo.cnt++;
      }else{
        Nodo nd = {j,1,0};
        mapa[mat[i][j]] = nd;
      }
    }
  }
  
  cout << ans << ENDL;


  return 0;
}