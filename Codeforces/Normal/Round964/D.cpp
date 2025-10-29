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
  string s, t;
  cin >> s >> t;
  
  int n = SZ(s), m = SZ(t);
  int j = 0;

  for (int i = 0; i < n; i++) {
    if (j < m && (s[i] == t[j] || s[i] == '?')) {
      if (s[i] == '?') {
        s[i] = t[j];
      }
      j++;
    }
  }

  if (j == m) {
    for (char &c : s) {
      if (c == '?') {
        c = 'a';
      }
    }
    cout << "YES" << ENDL;
    cout << s << ENDL;
  }
  else {
    cout << "NO" << ENDL;
  }
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