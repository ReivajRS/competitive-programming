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

  vi a(n);
  int total = 0;
  FOR (i, 0, n) {
    cin >> a[i];
    total += a[i];
  }

  vector<vector<bool>> dp(2, vector<bool>(total + 1));
  vi track(total + 1, -1);
  dp[0][0] = 1;

  FOR (i, 0, n) {
    FOR (j, a[i], total + 1) {
      if (dp[0][j - a[i]]) {
        dp[1][j] = 1;
        if (track[j] == -1) track[j] = i;
      }
    }
    dp[0] = dp[1];
  }

  if ((total & 1) || !dp[1][total / 2]) {
    cout << -1 << ENDL;
    return 0;
  }

  int act = total / 2;
  vector<bool> taken(n, 0);
  vi alice, bob;
  while (act > 0) {
    int idx = track[act];
    alice.pb(idx);
    taken[idx] = 1;
    act -= a[idx];
  }
  FOR (i, 0, n) if (!taken[i]) bob.pb(i);

  int i = 0, j = 0, sum_a = 0, sum_b = 0;
  while (i + j < n) {
    if (sum_a <= sum_b) {
      sum_a += a[alice[i]];
      cout << a[alice[i++]] << ' ';
    }
    else {
      sum_b += a[bob[j]];
      cout << a[bob[j++]] << ' ';
    }
  }
  cout << ENDL;

  return 0;
}