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

void solve() {
  string s;
  cin >> s;

  int n = SZ(s);
  vector<vi> z(n + 1, vi(n + 1, 0));

  ROF (i, n, 0) {
    ROF (j, n, 0) {
      if (s[i] == s[j]) {
        z[i][j] = z[i + 1][j + 1] + 1;
      }
    }
  }

  /*
    |A|ABC|AB
  */

  ll ans = 0;
  vector<vi> sum(n + 1, vi(n + 1, 0));
  FOR (i, 0, n) {
    FOR (j, i + 1, n) {
      if (z[i][j] >= j - i) {
        sum[j][j - i]++;
      }
    }
  }
  // FOR (i, 0, n) {
  //   FOR (j, 0, n) {
  //     cout << sum[i][j] << ' ';
  //   }
  //   cout << ENDL;
  // }
  FOR (i, 0, n) {
    FOR (j, 1, n) {
      sum[i][j] += sum[i][j - 1];
    }
    FOR (j, 1, n) {
      sum[i][j] += sum[i][j - 1];
    }
  }
  // cout << ENDL;
  // FOR (i, 0, n) {
  //   FOR (j, 0, n) {
  //     cout << sum[i][j] << ' ';
  //   }
  //   cout << ENDL;
  // }
  FOR (j, 0, n) {
    FOR (k, j + 1, n) {
      int l = min(z[j][k], k - j - 1) - 1;
      if (l >= 0) ans += sum[j][l];
    }
  }

  cout << ans << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int t;
  cin >> t;

  while (t--) {
    solve();
  }
  
  return 0;
}