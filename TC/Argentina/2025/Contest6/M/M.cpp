#include <bits/stdc++.h>
using namespace std;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  constexpr int D = 505, S = 305;

  vector<vector<bool>> can(D, vector<bool>(S));
  can[0][0] = true;
  for (int i = 1; i < D; ++i) {
    for (int j = 0; j < S; ++j) {
      for (int d = 0; d <= min(9, j); ++d) {
        if (can[i - 1][j - d]) {
          can[i][j] = true;
          break;
        }
      }
    }
  }

  int n;
  cin >> n;

  vector<int> prev(D);
  while (n--) {
    int x;
    cin >> x;

    vector<int> curr(D);

    auto fill = [&](int i, int s) -> bool {
      if (!i) {
        return !s;
      }
      while (i) {
        bool ok = false;
        for (int d = 0; d <= min(9, s); ++d) {
          if (can[i - 1][s - d]) {
            ok = true;
            curr[i] = d;
            s -= d;
            break;
          }
        }
        if (!ok) {
          return false;
        }
        --i;
      }
      return true;
    };

    auto untie = [&](auto&& untie, int i, int s) -> bool {
      if (!i || s < 0) {
        return false;
      }
      curr[i] = prev[i];
      if (untie(untie, i - 1, s - prev[i])) {
        return true;
      }
      if (9 * i < s && s < prev[i] + 1) {
        return false;
      }
      for (int d = prev[i] + 1; d <= min(9, s); ++d) {
        curr[i] = d;
        if (fill(i - 1, s - d)) {
          return true;
        }
      }
      return false;
    };
    assert(untie(untie, D - 1, x));

    vector<int> num;
    for (int i = D - 1; i; --i) {
      if (curr[i] || !num.empty()) {
        num.push_back(curr[i]);
      }
    }
    for (int d : num) {
      cout << d;
    }
    cout << '\n';

    prev = curr;
  }
}