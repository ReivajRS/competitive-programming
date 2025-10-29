#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using pi = pair<int,int>;

#define FOR(i,a,b) for(int i = (int)a;i<(int)b;i++)
#define ENDL '\n'

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int r,n;
  cin >> r >> n;
  vector<string> grid(r+3);
  FOR(i,0,r+3) cin >> grid[i];

  // contar asientos vacios por fila
  vi cnt(r+3,0);
  FOR(i,0,r+3){
    FOR(j,0,11){
      cnt[i] += (grid[i][j] == '-');
    }
  }

  //balance
  int cntIzq = 0,cntDer = 0;
  FOR(i,0,r+3){
    FOR(j,0,5){
      cntIzq+=(grid[i][j] == '#');
    }

    FOR(j,6,11){
      cntDer+=(grid[i][j] == '#');
    }
  }
  int m = r/2+2;

  auto getFila = [&]() -> int {
    int mx = 1;
    if(cnt[m] > cnt[mx]) mx = m;
    if(cnt[mx]) return mx;
    FOR(i,1,r+2){
      if(cnt[i] > cnt[mx]) mx = i;
      else if(cnt[i] == cnt[mx]){
        int d1 = min({i,abs(i-m+1),abs(r+2-i)});
        int d2 = min({mx,abs(mx-m+1),abs(r+2-mx)});
        if(d1 < d2) mx = i;
      }
    }
    return mx;
  };

  auto getColumn = [&](int fila) -> int {

    // 1
    if(grid[fila][4] == '-' && grid[fila][6] == '-'){
      if(cntIzq <= cntDer) return 4;
      else return 6;
    }
    if(grid[fila][4] == '-') return 4;
    if(grid[fila][6] == '-') return 6;

    // 2
    if(grid[fila][2] == '-' && grid[fila][8] == '-'){
      if(cntIzq <= cntDer) return 2;
      else return 8;
    }
    if(grid[fila][2] == '-') return 2;
    if(grid[fila][8] == '-') return 8;

    // 3
    if(grid[fila][0] == '-' && grid[fila][10] == '-'){
      if(cntIzq <= cntDer) return 0;
      else return 10;
    }
    if(grid[fila][0] == '-') return 0;
    if(grid[fila][10] == '-') return 10;

    // 4
    if(grid[fila][5] == '-') return 5;

    // 6
    if(grid[fila][1] == '-' && grid[fila][9] == '-'){
      if(cntIzq <= cntDer) return 1;
      else return 9;
    }
    if(grid[fila][1] == '-') return 1;
    if(grid[fila][9] == '-') return 9;

    return 0;
  };

  FOR(i,0,n){
    int fila = getFila();
    int colum = getColumn(fila);
    grid[fila][colum] = ('a'+i);
    cnt[fila]--;
    if(colum<5) cntIzq++;
    else if(colum>5) cntDer++;
  }

  FOR(i,0,r+3){
    cout << grid[i] << ENDL;
  }

}