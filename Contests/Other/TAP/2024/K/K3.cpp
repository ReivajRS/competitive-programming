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
  int D = 0;
  vector<vector<bool>> grid(n,vector<bool>(m,0));
  FOR(i,0,n){
    string s;
    cin >> s;
    FOR(j,0,m){
      grid[i][j] = s[j] == '#';
      D+=(s[j] == '#');
    }
  }

  auto puedeT = [&](int x,int y) -> bool {
    if(x+4>=n || y+2>=m) return false;
    if(grid[x][y] && grid[x][y+1] && grid[x][y+2] && grid[x+1][y+1] && grid[x+2][y+1] && grid[x+3][y+1] && grid[x+4][y+1]) return true;
    return false;
  };
  auto puedeA = [&](int x,int y) -> bool {
    if(x+4>=n || y+2>=m) return false;
    FOR(i,x,x+5){
      if(!grid[i][y]) return false;
      if(!grid[i][y+2]) return false;
    }
    if(!grid[x][y+1] || !grid[x+2][y+1]) return false;
    return true; 
  };
  auto puedeP = [&](int x,int y) -> bool {
    if(x+4>=n || y+2>=m) return false;
    FOR(i,x,x+5){
      if(!grid[i][y]) return false;
    }
    if(!grid[x][y+1] || !grid[x+2][y+1]) return false;
    FOR(i,x,x+3){
      if(!grid[i][y+2]) return false;
    }
    return true;
  };
  int cntT =0,cntA = 0,cntP = 0;
  FOR(i,0,n){
    FOR(j,0,m){
      //if(!grid[i][j]) continue;
      cntT+=puedeT(i,j);
      cntP+=puedeP(i,j);
      cntA+=puedeA(i,j);
    }
  }
  int cc = 0;
  FOR(A,0,cntT+1){
    FOR(B,0,cntA+1){
      int falta = D-(A*7+B*12);
      if(falta<0) continue;
      if(falta%10 == 0){
        assert(cc == 0);
        cc = 1;
        cout << A<< " "<< B << " "<< falta/10 << ENDL;
      }
    }
  }

  return 0;
}