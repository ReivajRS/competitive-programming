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
  
  int n, k;
  cin >> n >> k;

  const int mod = 1e9 + 7;
  vi dp1(n + 1, 0), dp2(n + 1, 0);
  dp1[1] = 1;

  for (int i = 0; i < k; i++) {
    for (int x = 1; x <= n; x++) {
      for (int v = x; v <= n; v += x) {
        dp2[v] += dp1[x];
        dp2[v] %= mod;
      }
    }
    swap(dp1, dp2);
    fill(ALL(dp2), 0);
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += dp1[i];
    ans %= mod;
  }
  cout << ans << ENDL;
  
  return 0;
}