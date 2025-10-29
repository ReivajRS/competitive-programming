#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i,a,b) for(int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'

ll ans = 0;

int n,k;
vector<string> grid;
vector<pi> o;
vi barcos;

bool check(vector<vi> &vis){
  for(auto [x,y]:o){
    if(!vis[x][y]) return false;
  }
  return true;
}
vi p;

void solve(vector<vi> &vis,int curr){
  if(curr == k) {
    ans+=check(vis);
    return;
  }

  
  int tam = barcos[curr];
  //cout << tam << ENDL;
  
  FOR(i,0,n){
    FOR(j,0,n){
      //checar horizontal
      
      if(j+tam <= n){
        bool usado = false;
        FOR(k,j,j+tam){
          if(vis[i][k]) {
            usado = true;
            break;
          }
        }

        if(!usado){
          FOR(k,j,j+tam){
            vis[i][k] = 1;
          }
          solve(vis,curr+1);
          FOR(k,j,j+tam){
            vis[i][k] = 0;
          }
        }
      }

      //checar vertical
      if(tam == 1) continue;
      if(i+tam <= n){
        bool usado = false;
        FOR(k,i,i+tam){
          if(vis[k][j]) {
            usado = true;
            break;
          }
        }

        if(!usado){
          FOR(k,i,i+tam){
            vis[k][j] = 1;
          }
          solve(vis,curr+1);
          FOR(k,i,i+tam){
            vis[k][j] = 0;
          }
        }
      }
    }
  }
}


signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> k;
  grid.resize(n);
  vector<vi> vis(n,vi(n,0));
  barcos.resize(k);
  FOR(i,0,n){
    cin >> grid[i];
    FOR(j,0,n){
      if(grid[i][j] == 'O') o.pb({i,j});
      else if(grid[i][j] == 'X') vis[i][j] = 1;
    }
  }
  FOR(i,0,k){
    cin >> barcos[i];
  }
  sort(barcos.rbegin(),barcos.rend());
  
  solve(vis,0);
  

  cout << ans << ENDL;




  return 0;
}