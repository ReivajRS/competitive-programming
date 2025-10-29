#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'

void solve() {
  int n, m;
  cin >> n >> m;

  int n2 = 4;
  while (n2 < n) {
    n2 *= 4;
  }

  vector<vector<ll>> mat(n, vector<ll>(m, 0));
  FOR (i, 0, n) {
    FOR (j, 0, m) {
      mat[i][j] = 4ll * i + j / 4 * n2 * 4 + j % 4;
    }
  }

  // CHECADOR
  // FOR (i, 0, n) {
  //   ll x1 = 0, x2 = 0;
  //   FOR (j, 0, m) {
  //     if (i + 4 < n && j + 4 < m) {
  //       x1 = mat[i][j] ^ mat[i][j + 1] ^ mat[i + 1][j] ^ mat[i + 1][j + 1];
  //       x2 = mat[i + 2][j + 2] ^ mat[i + 2][j + 3] ^ mat[i + 3][j + 2] ^ mat[i + 3][j + 3];
  //       assert(x1 == x2);
  //       x1 = mat[i][j + 2] ^ mat[i][j + 3] ^ mat[i + 1][j + 2] ^ mat[i + 1][j + 3];
  //       x2 = mat[i + 2][j] ^ mat[i + 2][j + 1] ^ mat[i + 3][j] ^ mat[i + 3][j + 1];
  //       assert(x1 == x2);
  //     }
  //   }
  // }

  cout << n * m << ENDL;
  FOR (i, 0, n) {
    FOR (j, 0, m) {
      cout << mat[i][j] << " \n"[j == m - 1];
    }
  }
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