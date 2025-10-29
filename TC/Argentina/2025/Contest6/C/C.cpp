#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) (int(x.size()))
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

void solve(){
  int n;
  string s;
  cin >> n >> s;
  int mal = 0;
  FOR(i,1,n+1){
    int x;
    cin >> x;
    mal += (x != i);
  }
  if(n == 2){
    cout << "Alice" << '\n';
    return;
  }
  if(mal == 2){
    if(s[0] == 'A') cout << "Alice" << '\n';
    else cout << "Bob" << '\n';
    return;
  }
  if(mal == 3 && n == 3){
    if(s[0] == 'A') cout << "Bob" << '\n';
    else cout << "Alice" << '\n';
    return;
  }
  cout << "Bob" << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while(t--) solve();

  return 0;
}