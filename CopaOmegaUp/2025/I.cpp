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
  
  int n;
  cin >> n;

  vector<tuple<int, int, int>> v(n);
  for (auto& [a, e, c] : v) {
    cin >> a >> e >> c;
  }

  vector<int> dp(n, 1);

  for (int i = 0; i < n; i++) {
    auto [a1, e1, c1] = v[i];
    for (int j = 0; j < i; j++) {
      auto [a2, e2, c2] = v[j];
      if (a1 > a2 && e1 > e2 && c1 > c2) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }

  cout << *max_element(dp.begin(), dp.end()) << '\n';
  
  return 0;
}