#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for (int i = (int)b - 1; i >= (int)a; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main() { __

  int n;
  cin >> n;
  vector<string> grid(n);
  FOR(i,0,n) cin >> grid[i];
  int ans = 0;
  FOR(i,0,n){
    FOR(j,0,n-1){
      if(grid[i][j] == 'N' && grid[i][j+1] == 'N'){
        ans++;
        grid[i][j] = 'B'; grid[i][j+1] = 'B';
      }
    }
  }
  cout << ans << ENDL;
  
  return 0;
}