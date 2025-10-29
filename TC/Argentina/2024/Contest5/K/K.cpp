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
  int n;
  cin >> n;
  ll ans = 0;
  int top = ceil(log2(n));
  FOR(i,0,top){
    vi a,b;
    FOR(j,1,n+1){
      if((1<<i) & j) a.pb(j);
      else b.pb(j);
      
    }
    cout << SZ(a) << " " << SZ(b) << " ";
      for(auto &x:a) cout << x << " ";
      for(auto &x:b) cout << x << " ";
      cout << endl;
      ll curr;
      cin >> curr;
      ans = max(ans,curr);
  }
  cout << "-1 " << ans << endl;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while(t--) solve();


  return 0;
}
  