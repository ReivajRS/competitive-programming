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

// 0 0 
// 0 1 
// 0 2
// 1 1
// 2 1
// 2 1 
// 3 1 
// 4 1 


// 0 0 
// 0 1
// 0 2
// 1 0
// 2 0
// 2 1
// 3 0
// 4 0


// TRIPLE FOR
// 0 0 0 
// 0 0 1
// 0 0 2

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n,m,h;
  cin >> n >> m >> h;
  vector<string> a(n);
  vector<string> b(n);
  FOR(i,0,n) cin >> a[i];
  FOR(i,0,n) cin >> b[i];

  FOR(i,0,n){
    int hay1a = false,hay1b = false;
    FOR(j,0,m) hay1a |= (a[i][j] == '1');
    FOR(j,0,h) hay1b |= (b[i][j] == '1');
    int aux = hay1a + hay1b;
    if(!(aux == 0 || aux == 2)){
      cout << -1 << ENDL;
      return 0;
    }
  }

  vector<tuple<int,int,int>> ansmx;
  FOR(i,0,n){
    FOR(j,0,m){
      FOR(k,0,h){
        if(a[i][j] == '1' && b[i][k] == '1') ansmx.pb({i,j,k});
      }
    }
  }
  sort(ALL(ansmx));
  cout << SZ(ansmx) << ENDL;
  for(auto [x,y,z] : ansmx){
    cout << x << " " << y << " " << z << ENDL;
  }
  vector<tuple<int,int,int>> ansmn;
  FOR(i,0,n){
    vi coordA,coordB;
    FOR(j,0,m){
      if(a[i][j] == '1') coordA.pb(j);
    }
    FOR(j,0,h){
      if(b[i][j] == '1') coordB.pb(j);
    }
    while(SZ(coordA) != SZ(coordB)){
      if(SZ(coordA) < SZ(coordB)) coordA.pb(coordA[0]);
      else coordB.pb(coordB[0]);
    }
    sort(ALL(coordA)),sort(ALL(coordB));
    FOR(j,0,SZ(coordA)) ansmn.pb({i,coordA[j],coordB[j]});
  }
  
  sort(ALL(ansmn));
  cout << SZ(ansmn) << ENDL;
  for(auto [x,y,z] : ansmn){
    cout << x << " " << y << " " << z << ENDL;
  }
  

  return 0;
}