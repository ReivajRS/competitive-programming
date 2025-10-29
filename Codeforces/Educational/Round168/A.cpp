#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

void solve() {
  string s;
  cin >> s;
  int last = -1;
  int idx = SZ(s);
  char c = 'a' - 1;
  FOR (i, 0, SZ(s)) {
    if (last == s[i]) {
      idx = i;
      c = s[i];
      break;
    }
    last = s[i];
  }
  if (idx == SZ(s)) {
    c = s.back();
  }
  c++;
  if (c > 'z')
    c = 'a';
  cout << s.substr(0, idx) + c + s.substr(idx) << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  
  return 0;
}