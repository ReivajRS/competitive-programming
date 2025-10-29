#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  string s, t;
  cin >> s >> t;

  if (t == "0") {
    cout << 0 << '\n';
    return 0;
  }

  int cs = int(count(s.begin(), s.end(), '(')), ct = int(count(t.begin(), t.end(), '('));
  for (int i = 0; i < cs * ct; ++i) {
    cout << "S(";
  }
  cout << 0 << string(cs * ct, ')') << '\n';
  
  return 0;
}