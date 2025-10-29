#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = a - 1; i >= b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main() { __
  
  string n,m;
  cin >> n >> m;
  if (n == m) {
    cout << 1 << ENDL;
    return 0;
  }
  int ans = 1;
  set<string> s;
  s.insert(n);
  while(ans < 100){
    vi cnt(10,0);
    FOR(i,0,SZ(n)){
      cnt[n[i] - '0']++;
    }
    string n2 = "";
    FOR(i,0,10){
      if(cnt[i] != 0){
        n2+=to_string(cnt[i]);
        n2+=char(i+'0');
      }
    }
    ans++;
    if(n2 == m){
      cout << ans << ENDL;
      return 0;
    }
    if(s.count(n2)) {
      cout << "Does not appear" << ENDL;
      return 0;
    }
    s.insert(n2);
    n = n2;
  }
  cout << "I'm bored" << ENDL;

  return 0;
}