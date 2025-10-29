#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
// AC2++
#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i,a,b) for(int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n,k;
  cin >> n >> k;

  vector<vi> grid(n, vi(n));
  vector<pi> num[n*n];
  FOR(i,0,n){
    FOR(j,0,n){
      cin >> grid[i][j];
      grid[i][j]--;
      num[grid[i][j]].pb({i,j});
    }
  }
  vector<vector<pi>> g(n*n+1);
  for(auto [vx,vy]:num[0]){
    g[n*n].pb({vx*n+vy,0});
  }
  FOR(i,0,k-1){
    for(auto [ux,uy]:num[i]){
      for(auto [vx,vy]:num[i+1]){
        int d = abs(ux-vx) + abs(uy-vy);
        g[ux*n+uy].pb({vx*n+vy,d});
      }
    }
  }
  vi d(n*n+1,1e9);
  d[n*n]=0;
  priority_queue<pi> pq;
  pq.push({0,n*n});
  while(!pq.empty()){
    auto [du, u] = pq.top();
    pq.pop();
    du = -du;
    if (du > d[u]) continue;
    //cout << u << ' ' << SZ(g[u]) << ENDL;
    for (auto &[v, w] : g[u]) if(du + w < d[v]) {
      d[v] = d[u] + w;
      pq.push({-d[v], v});
    }
  }
  int ans = 1e9;
  for (auto &[x, y] : num[k-1]) {
    ans = min(ans, d[x*n+y]);
  }
  if(ans == 1e9) ans = -1;
  cout << ans << ENDL;

  return 0;
}