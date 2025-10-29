#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)

constexpr int R = 7, C = 21;

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n;
  cin >> n;

  vector<vector<int>> ans(n, vector<int>(n));
  int c = 1;
  for (int stI = 0; stI < n; stI += R) {
    for (int stJ = 0; stJ < n; stJ += C) {
      for (int i = stI; i < min(n, stI + R); ++i) {
        for (int j = stJ; j < min(n, stJ + C); ++j) {
          ans[i][j] = c;
        }
      }
      ++c;
    }
  }
  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << ans[i][j] << " \n"[j == n - 1];
    }
  }
  
  return 0;
}