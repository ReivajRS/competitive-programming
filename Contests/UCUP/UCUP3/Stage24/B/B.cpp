#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vi = vector<ll>;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ENDL '\n'
 
constexpr ll INF = 3e15;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n,m;
  cin >> n >> m;
  vector<vi> zero(n,vi(n,INF)),uno(n,vi(n,INF)),dos(n,vi(n,INF));
  FOR(i,0,n){
    zero[i][i] = 0;
    uno[i][i] = 0;
    dos[i][i] = 0;
  }

  FOR(i,0,m){
    ll u,v,w,d;
    cin >> u >> v >> w >> d;
    u--,v--;
    zero[u][v] = min(zero[u][v],w);
    if(d == 1){
      uno[u][v] = min(uno[u][v],w); 
    }
    if(d == 2){
      uno[u][v] = min(uno[u][v],w);
      dos[u][v] = min(dos[u][v],w);
    }
  }

  FOR(k,0,n) FOR(i,0,n) FOR(j,0,n){
    zero[i][j] = min(zero[i][j], zero[i][k] + zero[k][j]);
    uno[i][j] = min(uno[i][j], uno[i][k] + uno[k][j]);
  }

  FOR(i,0,n){
    FOR(j,0,n){
      dos[i][j] = min(dos[i][j],zero[j][i] + 2 * uno[i][j]);
      dos[j][i] = min(dos[j][i],zero[i][j] + 2* uno[j][i]);
    }
  }

  FOR(k,0,n) FOR(i,0,n) FOR(j,0,n){
    dos[i][j] = min(dos[i][j], dos[i][k] + dos[k][j]);
  }

  FOR(i,0,n){
    FOR(j,0,n){
      if(dos[i][j] == INF) dos[i][j] = -1;
      cout << dos[i][j] << " ";
    }
    cout << ENDL;
  }

  return 0;
}