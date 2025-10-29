#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) begin(x),end(x)
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i,a,b) for(int i = (int)a - 1; i>= (int)b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main() { __
  int n, m;
  cin >> n >> m;

  vector<vi> mat(n, vi(m, -1));
  vi a;
  FOR (i, 0, n) {
    FOR (j, 0, m) {
      cin >> mat[i][j];
      if (mat[i][j] != -1) {
        a.pb(mat[i][j]);
      }
    }
  }

  sort(ALL(a));

  int mn = 1e9;

  FOR (k, 0, 4) {
    vector<unordered_set<int>> diag;
    int cnt = 0;
    
    FOR(i,0,m){
      unordered_set<int> dia;
      int j = 0;
      while(j<SZ(mat) && i-j >= 0){
        if(mat[j][i-j]!=-1)
          dia.insert(mat[j][i-j]);
        j++;
      }
      //diag
      if(SZ(dia))
        diag.pb(dia);

      if(i == m-1){
        
        FOR(k,1,n){
          dia.clear();
          int j = 0;
          while(j+k<SZ(mat) && i-j >= 0){
            if(mat[j+k][i-j]!= -1)
              dia.insert(mat[j+k][i-j]);
            j++;
          }
          //diag
          if(SZ(dia))
            diag.pb(dia);
        }
      }
    }

    int act = 0, c = 0;
    FOR (i, 0, SZ(a)) {
      if (!diag[act].count(a[i])) {
        cnt++;
      }
      c++;
      if (c == SZ(diag[act])) {
        c = 0, act++;
      }
    }

    mn = min(mn, cnt);

    vector<vi> aux(m,vi(n));
    FOR(i,0,n){
      FOR(j,0,m){
        aux[m - 1 - j][i] = mat[i][j];
      }
    }
    swap(aux,mat);
    swap(n,m);
  }
/*

  a b c
  d e f
  g h i

  c f i
  b e h
  a d g
 */
  // (i, j) => (m - 1 - j, i)

  cout << mn << ENDL;

  // for (auto &v : diags) {
  //   for (auto &x : v) {
  //     cout << x << ' ';
  //   }
  //   cout << ENDL;
  // }

  return 0;
}