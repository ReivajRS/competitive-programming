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

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  string s;
  cin >> s;

  int ans = SZ(s);
  vector<bool> cnt(27, 0);

  for (char c : s) {
    if (!cnt[c - 'A']) {
      cnt[c - 'A'] = 1;
      ans--;
    }
  }

  cout << ans << ENDL;
  
  return 0;
}