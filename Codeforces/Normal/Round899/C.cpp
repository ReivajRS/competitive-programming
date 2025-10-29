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

int n;
vector<ll> a;
vector<vector<ll>> dp;

ll f(int i, bool parity) {
  if (i >= n) return 0;
  ll &ans = dp[i][parity];
  if (ans != -1) return ans;
  if (i % 2 == parity) {
    ans = max(ans, f(i + 1, !parity) + a[i]);
    ans = max(ans, f(i + 2, parity) + a[i]);
  }
  else {
    ans = max(ans, f(i + 1, !parity));
  }
  ans = max(ans, f(i + 1, parity));
  return ans;
}

void solve() {
  cin >> n;
  
  a.resize(n);
  for (auto &x : a)
    cin >> x;

  dp.assign(n, vector<ll>(2, -1));
  cout << f(0, 0) << ENDL;
}

signed main() { __
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}