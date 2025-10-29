#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'

void solve(){
  int n;
  cin >> n;
  vector<vi> g(n+1);
  FOR(i,0,n){
    int x;
    cin >> x;
    g[x].pb(i+1);
  }

  auto dfs =[&](auto self,int u,int p) -> int {
    if(SZ(g[u]) == 0) return 1;
    int mx = -1;
    bool repetido = false;
    for(auto v:g[u]){
      if(v == p)continue;
      int aux = self(self,v,u);
      if(aux == mx){
        repetido = true;
      }else if(aux>mx){
        mx = aux;
        repetido = false;
      }
    }
    return mx + repetido;
  };

  cout << dfs(dfs,0,-1) << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while(t--) solve();

  return 0;
}