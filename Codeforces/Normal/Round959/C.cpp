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
  int n, mx;
  cin >> n >> mx;
  vector<ll> a(n), ps(n + 1, 0);
  FOR (i, 0, n) {
    cin >> a[i];
    ps[i + 1] = ps[i] + a[i];
  }
  vector<ll> dp(n + 1,0);
  ROF(i, n, 0) {
    bool f = a[i] <= mx;
    dp[i] = f;
    if (!f) {
      dp[i] += dp[i + 1];
      continue;
    }
    ll target = ps[i] + mx + 1;
    auto it = lower_bound(ALL(ps), target);
    if (it == ps.end()) {
      dp[i] += n - i - 1;
    } else {
      int pos = it - ps.begin() - 1;
      dp[i] += pos - i - 1 + dp[pos + 1];
    }
  }
  ll ans = 0;
  for (auto &x : dp) {
    ans += x;
  }
  cout << ans << ENDL;
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