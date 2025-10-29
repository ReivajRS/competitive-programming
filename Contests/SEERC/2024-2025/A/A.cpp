#include <bits/stdc++.h>
using namespace std;

using ll =  long long;
using vi = vector<int>;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<vi> g(n);
  vi deg(n,0);
  FOR(i,1,n){
    int u,v;
    cin >> u >> v;
    u--,v--;
    g[u].push_back(v);
    g[v].push_back(u);
    deg[u]++,deg[v]++;
  }

  vector<tuple<int,int,int>> ans;
  int raiz;
  auto dfs = [&](auto self,int u,int p) -> void {
    if(p != -1 && p != raiz) ans.push_back({raiz,p,u});
    for(auto v:g[u]){
      if(v == p) continue;
      self(self,v,u);
    }  
  };

  vector<pair<int,int>> inf(n);
  FOR(i,0,n){
    inf[i] = {-deg[i],i};
  }
  sort(inf.begin(),inf.end());
  auto [d,u] = inf[0];
  raiz = u;
  dfs(dfs,u,-1);

  cout << SZ(ans) << '\n';
  for(auto [x,y,z]:ans){
    cout << x+1 << " " << y+1 << " " << z+1 << '\n';
  }

  return 0;
}