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

  vector<vi> mat(n, vi(n));

  FOR (i, 0, n) {
    FOR (j, 0, n) {
      cin >> mat[i][j];
    }
  }

  auto check = [&]() -> bool {
    FOR (i, 0, n) {
      FOR (j, 1, n) {
        if (mat[i][j] < mat[i][j - 1])
          return false;
      }
    }
    FOR (j, 0, n) {
      FOR (i, 1, n) {
        if (mat[i][j] < mat[i - 1][j])
          return false;
      }
    }
    return true;
  };

  auto rotate = [&]() -> void {
    vector<vi> mat2(n, vi(n));
    FOR (i, 0, n) {
      FOR (j, 0, n) {
        mat2[n - j - 1][i] = mat[i][j];
      }
    }
    mat = mat2;
  };

  FOR (i, 0, 4) {
    if (check()) {
      cout << i << ENDL;
      return 0;
    }
    rotate();
  }
  
  return 0;
}