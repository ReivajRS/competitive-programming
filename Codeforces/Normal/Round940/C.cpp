#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) (ll) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define ROF(i, a, b) for (ll i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const ll MOD = 1e9 + 7;

void solve() {
  ll n, k;
  cin >> n >> k;
  set<ll> st;
  FOR (i, 0, k) {
    ll x, y;
    cin >> x >> y;
    st.insert(x);
    st.insert(y);
  }
  ll n2 = n - SZ(st);
  vi dp(n2 + 1, -1);
  auto f = [&dp](auto& self, ll n) -> ll {
    if (n == 0) return 1;
    if (n < 0)  return 0;
    if (dp[n] != -1)  return dp[n];
    return dp[n] = ((self(self, n - 1) % MOD) + ((2 * (n - 1) % MOD) * (self(self, n - 2) % MOD)) % MOD) % MOD;
  };
  cout << f(f, n2) << ENDL;
}

signed main() { __
  ll tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}