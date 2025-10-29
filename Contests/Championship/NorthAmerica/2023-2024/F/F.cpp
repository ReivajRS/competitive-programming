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

string O,G,R;
vector<pair<char,int>> ans;

void moveO(int x){
  x%=10;
  if(!x) return;
  ans.pb({'o',x});
  while(x--) rotate(O.begin(),O.end()-1,O.end());
}
void moveG(int x){
  x%=10;
  if(!x) return;
  ans.pb({'g',x});
  while(x--) rotate(G.begin(),G.end()-1,G.end());
}
void moveR(int x){
  x%=10;
  if(!x) return;
  ans.pb({'r',x});
  while(x--) rotate(R.begin(),R.end()-1,R.end());
}
void moveC(int x){
  x%=10;
  if(!x) return;
  ans.pb({'c',x});
  while(x--){
  string aux(ALL(O));
  FOR(i,0,3) O[i] = G[i];
  FOR(i,0,3) G[i] = R[i];
  FOR(i,0,3) R[i] = aux[i];
  }
  
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> O >> G >> R;

  // PASAR LAS O DE G A O
  FOR(_,0,10){
    FOR(i,0,10){
      if(G[i] == 'o'){
        int aux = 0;
        ROF(jj,10,0) if(O[jj] != 'o') {
          aux = jj;
          break;
        }

        moveO(9-aux);
        moveG(12-i);
        moveC(1);
        moveO(1);
        moveC(2);
        moveO(7);
      }
    }
  }

  // PASAR LAS O DE R A O
  FOR(_,0,10){
    FOR(i,0,10){
      if(R[i] == 'o'){
        int aux = 0;
        ROF(jj,10,0) if(O[jj] != 'o') {
          aux = jj;
          break;
        }
        moveR(9-i);
        moveO(12-aux);
        moveC(1);
        moveR(1);
        moveC(2);
        moveR(7);
      }
    }
  }

  // PASAR LAS G DE R A G
  FOR(_,0,10){
    FOR(i,0,10){
      if(R[i] == 'g'){
        int aux = 0;
        ROF(jj,10,0) if(G[jj] != 'g') {
          aux = jj;
          break;
        }
        moveG(9-aux);
        moveR(12-i);
        moveC(1);
        moveG(1);
        moveC(2);
        moveG(7);
      }
    }
  }
  cout << SZ(ans) << ENDL;
  for (auto [x, y] : ans) {
    cout << x << y << ENDL;
  }

  return 0;
}