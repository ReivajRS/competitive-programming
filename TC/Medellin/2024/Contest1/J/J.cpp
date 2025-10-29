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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<vi> a(35);
  FOR(i,0,n){
    FOR(j,0,30){
      if(i & (1<<j)) a[j].pb(i);
    }
  }
  int cnt = 0;
  vector<vi> res(35);
  FOR(i,0,30){
    if(SZ(a[i])){
      res[cnt].pb(SZ(a[i]));
      for(auto x:a[i]) res[cnt].pb(x);
      cnt++;
    }
  }
  cout << cnt << endl;
  FOR(i,0,cnt){
    for(auto x:res[i]) cout << x << " ";
    cout << endl;
  }
  string s;
  cin >> s;
  int ans = 0;
  FOR(i,0,SZ(s)){
    if(s[i] == '1'){
      ans |= (1<<i);
    }
  }
  if(!ans) ans = n;
  cout << ans << endl;

  return 0;
}