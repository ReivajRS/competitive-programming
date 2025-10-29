#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve() {
  int n, k;
  cin >> n >> k;

  vector<ll> a(n);
  for (auto &x : a)
    cin >> x;
  
  vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, -1));

  auto f = [&](auto self, int i, int w) -> ll {
    if (i >= n)
      return 0;
    ll &ans = dp[i][w];
    if (ans != -1)
      return ans;
    ans = self(self, i + 1, w) + a[i];
    ll mn = a[i];
    FOR(j, 1, k - w + 1) {
      if (i + j >= n)
        break;
      mn = min(mn, a[i + j]);
      ans = min(ans, self(self, i + j + 1, w + j) + mn * (j + 1));
    }
    return ans;
  };

  cout << f(f, 0, 0) << ENDL;
}

signed main() { __
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}