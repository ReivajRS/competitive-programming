#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
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
  int n, m;
  cin >> n >> m;
  vector<vi> mat(n, vi(m));
  FOR (i, 0, n) {
    FOR (j, 0, m) {
      cin >> mat[i][j];
    }
  }
  vector<vi> mat2 = mat;
  if (n == 1 && m == 1) {
    cout << -1 << ENDL;
    return;
  }
  FOR (i, 0, n) {
    FOR (j, 0, m) {
      if (mat2[i][j] == mat[i][j]) {
        if (m == 1) {
          swap(mat2[i][j], mat2[(i + 1) % n][j]);
        } else {
          swap(mat2[i][j], mat2[i][(j + 1) % m]);
        }
      }
    }
  }
  FOR (i, 0, n) {
    FOR (j, 0, m) {
      assert(mat2[i][j] != mat[i][j]);
      cout << mat2[i][j] << " \n"[j == m - 1];
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