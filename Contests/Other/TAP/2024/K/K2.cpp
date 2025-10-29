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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n,m;
  cin >> n >> m;
  vector<vector<bool>> grid(n,vector<bool>(m,0));
  FOR(i,0,n){
    string s;
    cin >> s;
    FOR(j,0,m){
      grid[i][j] = s[j] == '#';
    }
  }



  auto puedeT = [&](int x,int y) -> bool {
    if(x+4>=n || y+2>=m) return false;
    if(grid[x][y] && grid[x][y+1] && grid[x][y+2] && grid[x+1][y+1] && grid[x+2][y+1] && grid[x+3][y+1] && grid[x+4][y+1]) return true;
    return false;
  };
  auto puedeA = [&](int x,int y) -> bool {
    if(x+4>=n || y+2>=m) return false;
    if(grid[x+1][y+1]) return false;
    FOR(i,x,x+5){
      if(!grid[i][y]) return false;
      if(!grid[i][y+2]) return false;
    }
    if(!grid[x][y+1] || !grid[x+2][y+1]) return false;
    return true; 
  };
  auto puedeP = [&](int x,int y) -> bool {
    if(x+4>=n || y+2>=m) return false;
    if(grid[x+1][y+1]) return false;
    FOR(i,x,x+5){
      if(!grid[i][y]) return false;
    }
    if(!grid[x][y+1] || !grid[x+2][y+1]) return false;
    FOR(i,x,x+3){
      if(!grid[i][y+2]) return false;
    }
    return true;
  };

  auto marcarT = [&](int x,int y) -> void {
    grid[x][y] = grid[x][y+1] = grid[x][y+2] = grid[x+1][y+1] = grid[x+2][y+1] = grid[x+3][y+1] = grid[x+4][y+1] = 0;
  };
  auto marcarA = [&](int x,int y) -> void {
    FOR(i,x,x+5){
      grid[i][y] = 0;
      grid[i][y+2] = 0;
    }
    grid[x][y+1] = grid[x+2][y+1] = 0;
  };
  auto marcarP = [&](int x,int y) -> bool {
    FOR(i,x,x+5){
      grid[i][y] = 0;
    }
    grid[x][y+1] = grid[x+2][y+1] = 0;
    FOR(i,x,x+3){
      grid[i][y+2] = 0;
    }
    return true;
  };

  int cntT =0,cntA = 0,cntP = 0;
  FOR(i,0,n){
    FOR(j,0,m){
      if(!grid[i][j]) continue;
      if(puedeA(i,j)){
        if(puedeP(i+3,j+2) || puedeT(i+3,j+1)){
          marcarP(i,j);
          cntP++;
        }else{
          marcarA(i,j);
          cntA++;
        }
      }else if(puedeP(i,j)){
        marcarP(i,j);
        cntP++;
      }
      else if(puedeT(i,j)) {
        marcarT(i,j);
        cntT++;
      }
    }
  }

  //Ax+By+Cz = D

  cout << cntT << " " << cntA << " " << cntP << ENDL;

  return 0;
}