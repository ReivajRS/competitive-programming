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

  int n;
  cin >> n;
  int d = 0;
  vector<vector<pi>> nivel(n);
  FOR(i,0,n){
    string s;
    cin >> s;
    int tabs=0,spaces =0;
    for(auto c:s){
      tabs+=c=='t';
      spaces+=c=='s';
    }
    if(s.back()=='}') d--;
    nivel[d].pb({tabs,spaces});
    if(s.back() == '{') d++;
  }

  
  if(SZ(nivel[1]) == 0){
    cout << 1 << ENDL;
    return 0;
  }
  FOR(ans,1,1e6){
    bool ok = true;
    int subida = (nivel[1][0].first * ans + nivel[1][0].second) - (nivel[0][0].first * ans + nivel[0][0].second);
    int depth = 0;
    FOR(i,0,n){
      FOR(j,0,SZ(nivel[i])-1){
        int curr = nivel[i][j].first * ans + nivel[i][j].second;
        int sig = nivel[i][j+1].first * ans + nivel[i][j+1].second;
        if(curr != sig or curr != depth){
          ok = false;
          break;
        }
      }
      if(!ok) break;
      depth+=subida;
    }
    if(ok){
      cout << ans << ENDL;
      return 0;
    }
  }
  cout << -1 << ENDL;

  return 0;
}