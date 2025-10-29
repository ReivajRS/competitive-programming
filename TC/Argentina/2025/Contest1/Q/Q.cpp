#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<pi> pts(n);
  FOR(i,0,n){
    cin >> pts[i].first >> pts[i].second;
  }

  auto dist = [&](int i,int j) -> int {
    return abs(pts[i].first-pts[j].first) +abs(pts[i].second-pts[j].second);
  };
  vi mnDist(n,1e9);
  FOR(i,0,n){
    FOR(j,0,n){
      if(i == j) continue;
      mnDist[i] = min(mnDist[i],dist(i,j));
    }
  }
  vector<vi> g(n);
  FOR(i,0,n){
    FOR(j,0,n){
      if(i == j) continue;
      if(mnDist[i] == dist(i,j)) g[i].push_back(j);
    }
  }
  vi vis(n,0);
  vi taken(n,0);
  auto dfs = [&](auto self,int u) -> void{
    vis[u] = 1;
    for(auto v:g[u]){
      if(!vis[v]) self(self,v);
    }
  };
  auto dfs2 = [&](auto self,int u) -> void{
    taken[u] = 1;
    for(auto v:g[u]){
      if(!taken[v]) self(self,v);
    }
  };
  vi color;
  FOR(i,0,n){
    if(taken[i]) continue;
    vis.assign(n,0);
    dfs(dfs,i);
    vi comp;
    FOR(i,0,n) if(vis[i]) comp.push_back(i);
    int m = SZ(comp);
    bool ok = true;
    FOR(j,0,m){
      FOR(k,0,m){
        if(j == k) continue;
        if(mnDist[i] != dist(comp[j],comp[k])){
          ok =false;
        }
      }
    }
    if(!ok){
      color.push_back(1);
      taken[i] = 1;
    }else{
      color.push_back(SZ(comp));
      dfs2(dfs2,i);
    }
  }

  vector<vi> dp(n,vi(SZ(color)));
  dp[0][0] = 1;
  FOR(i,1,n){
    FOR(j,1,SZ(color)){
      dp[i][j] += dp[i-1][j-1];
      if(i-color[j] >=0){
        dp[i][j] += dp[i-color[j]][j-1];
      }
    }
  }
  ll ans = 0;
  FOR(i,0,n){
    
  }

  return 0;
}