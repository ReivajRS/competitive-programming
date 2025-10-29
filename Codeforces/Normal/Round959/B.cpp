#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
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
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  FOR (i, 0, n) {
    if (s[i] == t[i]) {
      if (s[i] == '1' && t[i] == '1') {
        cout << "YES" << ENDL;
        return;
      }
      continue;
    }
    cout << (s[i] == '1' ? "YES" : "NO") << ENDL;
    return;
  }
  cout << "YES" << ENDL;
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