#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector<vi> tarjan(vector<vi>& g){
  int n = SZ(g),timer = 0;
  vector<vi> scc;
  vi tin(n,-1),low(n,0),vis(n,0);
  stack<int> st;
  auto dfs = [&](auto self,int u) -> void{
    tin[u] = low[u] = timer++;
    st.push(u);
    vis[u] = 1;
    for(int v:g[u]){
      if(tin[v] == -1) self(self,v);
      if(vis[v]) low[u] = min(low[u],low[v]);
    }
    if(low[u] == tin[u]){
      scc.pb({});
      while(1){
        int v = st.top();
        st.pop();
        vis[v] = 0;
        scc.back().pb(v);
        if(u==v) break;
      }
    }
  };
  FOR(i,0,n) if (tin[i] == -1) dfs(dfs,i);
  return scc;
}

signed main() { __
  
  int n,m;
  cin >> n >> m;
  vector<vi> g(n,vi());
  FOR(i,0,m){
    int u,v;
    cin >> u >> v;
    u--,v--;
    g[u].pb(v);
  }
  vector<vi> scc2 = tarjan(g);
  int t = SZ(scc2);
  vector<int> scc(n);
  
  FOR(i,0,t){
    for(auto x:scc2[i]){
      scc[x] = i;
    }
  }

  vector<bool> salida(n,0);
  FOR(u,0,n){
    for(auto v:g[u]){
      if(scc[u] != scc[v]){
        salida[scc[v]] = true;
      }
    }
  }

  int ans = 0;
  FOR(i,0,t){
    if(!salida[i]) ans++;
  }
  cout << ans << ENDL;


  return 0;
}