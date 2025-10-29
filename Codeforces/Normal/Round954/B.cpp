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

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vi> mat(n, vi(m));
  FOR (i, 0, n) {
    FOR (j, 0, m) {
      cin >> mat[i][j];
    }
  }
  FOR (i, 0, n) {
    FOR (j, 0, m) {
      int mx = 0;
      if (i - 1 >= 0) {
        mx = max(mx, mat[i - 1][j]);
      }
      if (i + 1 < n) {
        mx = max(mx, mat[i + 1][j]);
      }
      if (j - 1 >= 0) {
        mx = max(mx, mat[i][j - 1]);
      }
      if (j + 1 < m) {
        mx = max(mx, mat[i][j + 1]);
      }
      if (mx >= mat[i][j])
        continue;
      mat[i][j] = mx;
    }
  }
  FOR (i, 0, n) {
    FOR (j, 0, m) {
      cout << mat[i][j] << ' ';
    }
    cout << ENDL;
  }
}

signed main() { __
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}