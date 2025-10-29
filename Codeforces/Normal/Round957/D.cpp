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
  int n, m, k;
  cin >> n >> m >> k;
  string s;
  cin >> s;
  s = 'L' + s + 'L';
  vi logs;
  FOR (i, 0, SZ(s)) {
    if (s[i] == 'L')
      logs.pb(i);
  }
  /*
    Log = 0
    Water = 1
  */
  vector<vi> dp(SZ(s) + 1, vi(2, -1));
  auto f = [&](auto &f, int pos, bool where) -> int {
    // cout << pos << ' ' << where << ENDL;
    if (pos == SZ(s))
      return 1;
    int &ans = dp[pos][where];
    if (ans != -1)
      return ans;
    ans = 0;
    if (!where) {
      // At log
      FOR (jump, 1, m + 1) {
        if (pos + jump > SZ(s))
          continue;
        char next_where = s[pos + jump];
        if (next_where == 'C')
          continue;
        ans += f(f, pos + jump, next_where == 'W');
      }
    }
    else {
      // At water
      auto it = lower_bound(ALL(logs), pos + 1);
      if (it != logs.end()) {
        int next_log = *it;
        if (next_log - pos <= k) {
          ans += f(f, next_log, 0);
        }
      }
    }
    return ans;
  };

  int ans = f(f, 0, 0);
  if (ans > 0) {
    cout << "YES" << ENDL;
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