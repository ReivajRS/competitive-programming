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
  int n;
  cin >> n;
  
  vector<string> mat(2);
  cin >> mat[0];
  cin >> mat[1];

  int ans = 0;

  FOR (i, 0, 2) {
    FOR (j, 0, n) {
      if (mat[i][j] == 'x')
        continue;
      int cnt = 0;
      if (i > 0 && mat[i - 1][j] != 'x') {
        cnt++;
      }
      if (i == 0 && mat[i + 1][j] != 'x') {
        cnt++;
      }
      if (j > 0 && mat[i][j - 1] != 'x') {
        cnt++;
      }
      if (j + 1 < n && mat[i][j + 1] != 'x') {
        cnt++;
      }
      if (cnt == 3) {
        int cnt2 = 0;
        if (i == 0) {
          if (j > 0 && mat[i + 1][j - 1] == 'x')
            cnt2++;
          if (j + 1 < n && mat[i + 1][j + 1] == 'x')
            cnt2++;
        }
        if (i == 1) {
          if (j > 0 && mat[i - 1][j - 1] == 'x')
            cnt2++;
          if (j + 1 < n && mat[i - 1][j + 1] == 'x')
            cnt2++;
        }
        if (cnt2 == 2)
          ans++;
      }
    }
  }

  cout << ans << ENDL;

}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  
  return 0;
}