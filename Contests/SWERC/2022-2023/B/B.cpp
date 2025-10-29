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

ll n, h;
vector<ll> a;
ll dp[301][301];

ll diag(ll l, ll r) { return (r - l + 1) / 2; }

ll solve(int l, int r) {
  if (l == r) return h;
  ll &ans = dp[l][r];
  if (ans != -1) return ans;
  ans = 1e18;
  for (int m = l; m < r; m++)
    ans = min(ans, solve(l, m) + solve(m + 1, r) - max(0ll, h + 1 - diag(a[l], a[r])));
  return ans;
}

signed main() { __
  cin >> n >> h;

  a.resize(n);
  for (auto &x : a) cin >> x;
  
  memset(dp, -1, sizeof dp);
  cout << solve(0, n - 1) << ENDL;
  
  return 0;
}