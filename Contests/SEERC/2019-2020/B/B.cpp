#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i,a,b) for(int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'

constexpr ll INF = 1e15;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, s1, s2;
  cin >> n >> s1 >> s2;
  vi x(n), t(n), y(n), r(n);
  FOR (i, 0, n) {
    cin >> x[i] >> t[i] >> y[i] >> r[i];
  }

  vi p(n);
  iota(ALL(p), 0);
  sort(ALL(p), [&](int i, int j) { return make_pair(x[i], -y[i]) < make_pair(x[j], -y[j]); });

  vector<vector<ll>> dp(s1 + 1, vector<ll>(s2 + 1, INF));
  dp[s1][s2] = 0;
  
  ROF (k, n, 0) {
    int i = p[k];
    FOR (ca, 0, s1 + 1) {
      FOR (cb, 0, s2 + 1) {
        ll &ans = dp[ca][cb];
        if (ca != s1) {
          int nca = ca + x[i], ncb = cb;
          if (nca > s1) {
            ncb = min(s2, ncb + nca - s1);
            nca = s1;
          }
          ans = min(ans, dp[nca][ncb] + t[i]);
        }
        ans = min(ans, dp[ca][min(s2, cb + y[i])] + r[i]);
      }
    }
  }
  ll ans = dp[0][0];
  if (ans == INF) ans = -1;
  cout << ans << ENDL;

  return 0;
}