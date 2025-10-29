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
  
  int n, m;
  cin >> n >> m;

  vector<vector<bool>> mat(n, vector<bool>(m));
  FOR (i, 0, n) {
    FOR (j, 0, m) {
      char c;
      cin >> c;
      mat[i][j] = (c == '#');
    }
  }

  auto get_cnt = [&](int i, int j) -> int {
    int cnt = 0;
    for (int k = 0; k < 5 && i + k < n && mat[i + k][j]; k++)
      cnt++;
    return cnt;
  };

  auto can_T = [&](int i, int j) -> bool {
    if (i + 4 >= n || j - 2 < 0) return false;
    return mat[i][j] && mat[i][j - 1] && mat[i][j - 2]
      && mat[i + 1][j - 1] && mat[i + 2][j - 1] && mat[i + 3][j - 1] && mat[i + 4][j - 1];
  };

  auto can_A = [&](int i, int j) -> bool {
    if (i + 4 >= n || j - 2 < 0) return false;
    return mat[i][j] && mat[i][j - 1] && mat[i][j - 2]
      && mat[i + 2][j - 1]
      && mat[i + 1][j] && mat[i + 2][j] && mat[i + 3][j] && mat[i + 4][j]
      && mat[i + 1][j - 2] && mat[i + 2][j - 2] && mat[i + 3][j - 2] && mat[i + 4][j - 2];
  };

  auto can_P = [&](int i, int j) -> bool {
    if (i + 4 >= n || j - 2 < 0) return false;
    return mat[i][j] && mat[i][j - 1] && mat[i][j - 2]
      && mat[i + 2][j - 1]
      && mat[i + 1][j] && mat[i + 2][j]
      && mat[i + 1][j - 2] && mat[i + 2][j - 2] && mat[i + 3][j - 2] && mat[i + 4][j - 2];
  };

  auto mark_T = [&](int i, int j) -> void {
    mat[i][j] = mat[i][j - 1] = mat[i][j - 2]
      = mat[i + 1][j - 1] = mat[i + 2][j - 1] = mat[i + 3][j - 1] = mat[i + 4][j - 1] = 0;
  };

  auto mark_A = [&](int i, int j) -> void {
    mat[i][j] = mat[i][j - 1] = mat[i][j - 2]
      = mat[i + 2][j - 1]
      = mat[i + 1][j] = mat[i + 2][j] = mat[i + 3][j] = mat[i + 4][j]
      = mat[i + 1][j - 2] = mat[i + 2][j - 2] = mat[i + 3][j - 2] = mat[i + 4][j - 2] = 0;
  };

  auto mark_P = [&](int i, int j) -> void {
    mat[i][j] = mat[i][j - 1] = mat[i][j - 2]
      = mat[i + 2][j - 1]
      = mat[i + 1][j] = mat[i + 2][j]
      = mat[i + 1][j - 2] = mat[i + 2][j - 2] = mat[i + 3][j - 2] = mat[i + 4][j - 2] = 0;
  };

  vi ans(3, 0);

  ROF (j, m, 0) {
    ROF (i, n, 0) {
      if (!mat[i][j]) continue;
      int cnt = get_cnt(i, j);
      if (cnt == 5 && can_A(i, j)) {
        mark_A(i, j);
        ans[1]++;
      }
      if (cnt == 3 && can_P(i, j)) {
        mark_P(i, j);
        ans[2]++;
      }
      if (cnt == 1 && can_T(i, j)) {
        mark_T(i, j);
        ans[0]++;
      }
    }
  }

  cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << ENDL;

  return 0;
}