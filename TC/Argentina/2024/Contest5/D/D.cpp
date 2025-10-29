#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'

void solve(){
  ll a,b,c;
  cin >> a >> b >> c;
  ll suma = a+b+c;
  if(suma%9 != 0){
    cout << "NO" << ENDL;
    return;
  }
  ll aux = suma/9;
  if(aux>min({a,b,c})){
    cout << "NO" << ENDL;
    return;
  }
  cout << "YES" << ENDL;
  return;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while(t--) solve();


  return 0;
}
  