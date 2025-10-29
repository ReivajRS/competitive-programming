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

void solve(){
  int n;
  cin >> n;
  vector<vi> g(n);
  FOR(i,1,n){
    int u,v;
    cin >> u >> v;
    u--,v--;
    g[u].pb(v);
  }
  vi dep(n,0);
  vi sz(n,1);
  auto dfs = [&](auto self,int u,int d) -> int {
    dep[u] = d;
    for(auto v:g[u]){
      sz[u] += self(self,v,d+1);
    }
    return sz[u];
  };
  dfs(dfs,0,1);
  FOR(i,0,n){
    cout << dep[i] << " " << n - sz[i]+1 << ENDL; 
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while(t--) solve();

  return 0;
}