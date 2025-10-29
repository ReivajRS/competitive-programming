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
  int n;
  cin >> n;
  
  vi a(n);
  for (auto &x : a)
    cin >> x;
  
  vector<vi> dp(n + 1, vi(1 << 2, -1));

  auto f = [&](auto &f, int i, int mask) -> int {
    if (i == n)
      return 0;
    int &ans = dp[i][mask];
    if (ans != -1)
      return ans;
    ans = (a[i] != 0) + f(f, i + 1, 0);
    if (a[i] <= 4) {
      bool lmark = (mask & 1);
      bool rmark = (mask & 2);
      if (lmark && (a[i] <= 2 || (a[i] <= 4 && rmark)))
        ans = f(f, i + 1, 0);
      if (a[i] <= 2 || rmark) {
        int nmask = 1;
        ans = min(ans, 1 + f(f, i + 1, nmask));
      }
      if (lmark && a[i] <= 4) {
        int nmask = 2;
        ans = min(ans, 1 + f(f, i + 1, nmask));
      }
    }
    return ans;
  };

  cout << f(f, 0, 0) << ENDL;
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