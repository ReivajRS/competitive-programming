#include <bits/stdc++.h>
using namespace std;

using ll =  long long;
using vi = vector<int>;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ENDL '\n'

void solve(){
  int n,m;
  cin >> n >> m;
  vector<vi> a(n,vi(m));
  FOR(i,0,n) FOR(j,0,m) cin >> a[i][j];
  vi quitar(n);
  FOR(i,0,n) quitar[i] = a[i][0];
  sort(quitar.begin(),quitar.end());
  FOR(i,1,m){
    vi curr(n);
    FOR(j,0,n) curr[j] = a[j][i];
    sort(curr.begin(),curr.end());

    int tam = SZ(quitar);
    int faltan = tam;
    int k = 0;
    FOR(j,0,tam){
      if(quitar[j] > curr[k]){
        k++;
        faltan--;
        if(k == n) break;
      }
    }
    quitar.clear();
    if(faltan == 0) break;
    FOR(j,n-faltan,n){
      quitar.push_back(curr[j]);
    }
  }
  if(SZ(quitar) == 0){
    cout << "YES" << ENDL;
  }else{
    cout << "NO" << ENDL;
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while(t--) solve();

  return 0;
}