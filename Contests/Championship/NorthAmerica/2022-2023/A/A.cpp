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

  int t;
  cin >> t;
  while(t--){
  ll N,D;
  cin >> N >> D;
  __int128_t n = N,d = D+1,aux = 1;
  int ans = 0;
  while(aux < n){
    aux*=d;
    ans++;
  }
  cout << ans << ENDL;
  }

  return 0;
}