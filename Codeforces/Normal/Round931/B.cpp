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

vector<ll> dp(101, 1e10);

void pre() {
  vi c = {1,3,6,10,15};
  for (auto &v : c) {
    dp[v] = 1;
  }
  FOR (i, 0, 101) {
    for (auto &v : c) {
      if (i >= v)
        dp[i] = min(dp[i], dp[i - v] + 1);
    }
  }
}

void solve() {
  ll n;
  cin >> n;
  if (n <= 100) {
    cout << dp[n] << ENDL;
    return;
  }
  int l = ceil(1.0*(n-100)/15);
  cout << l + dp[n - l*15] << ENDL;
}

signed main() { __
  pre();
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}