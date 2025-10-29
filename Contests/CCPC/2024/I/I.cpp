#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

void solve(){
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  FOR(i,1,n){
    int u,v;
    cin >> u >> v;
    u--,v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<pair<int,int>> ans;

  auto dfs = [&](auto self,int u,int p) -> int {
    vector<int> hijos;
    for(auto v:g[u]){
      if(v == p) continue;
      int sobra = self(self,v,u);
      if(sobra == -1){
        hijos.push_back(v);
      }else{
        hijos.push_back(sobra);
      }     
    }
    int N = SZ(hijos);
    for(int i=1;i<N;i+=2){
      ans.push_back({hijos[i-1],hijos[i]});
    }

    if(SZ(hijos) % 2){
      return hijos.back();
    }else return -1;
  };

  int raiz = 0;
  FOR(i,0,n){
    if(SZ(g[i]) % 2 == 0){
      raiz = i;
      break;
    }
  }

  int s = dfs(dfs,raiz,-1);
  if(s != -1){
    cout << -1 << '\n';
    return;
  }
  cout << SZ(ans) << '\n';
  for(auto &[u,v]:ans){
    cout << u+1 << " " << v+1 << '\n';
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while(t--) solve();

  return 0;
}