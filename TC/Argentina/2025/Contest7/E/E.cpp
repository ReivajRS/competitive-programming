#include <bits/stdc++.h>
using namespace std;

int dig(int r, int c) {
  cout << "dig " << r + 1 << ' ' << c + 1 << endl;
  int ok;
  cin >> ok;
  return ok;
}

int scan(int r, int c) {
  cout << "scan " << r+1 << ' ' << c+1 << endl;
  int d;
  cin >> d;
  return d;
}

void solve() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> cells;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cells.emplace_back(i, j);
    }
  }

  vector<pair<int, int>> cand = {
    {0, 0},
    {0, m - 1},
    {n - 1, 0},
    {n - 1, m - 1}
  };
  vector<vector<vector<vector<int>>>> marks(n, vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(m))));
  for (auto [i, j] : cand) {
    int d = scan(i, j);
    for (auto [r1, c1] : cells) {
      int d1 = abs(r1 - i) + abs(c1 - j);
      for (auto [r2, c2] : cells) {
        if (r1 != r2 || c1 != c2) {
          int d2 = abs(r2 - i) + abs(c2 - j);
          marks[r1][c1][r2][c2] += d1 + d2 == d;
        }
      }
    }
  }

  auto cancelAll = [&](int r, int c) {
    for (auto [r2, c2] : cells) {
      marks[r][c][r2][c2] = marks[r2][c2][r][c] = 0;
    }
  };

  int tries = 3;
  pair<int, int> taken(-1, -1);
  for (auto [r1, c1] : cells) {
    for (auto [r2, c2] : cells) {
      if (marks[r1][c1][r2][c2] != int(cand.size())) {
        continue;
      }
      --tries;
      if (dig(r1, c1)) {
        if (!tries) {
          exit(0);
        }
        --tries;
        if (dig(r2, c2)) {
          return;
        }
        cancelAll(r2, c2);
        taken = {r1, c1};
        break;
      }
      if (!tries) {
        exit(0);
      }
      cancelAll(r1, c1);
      break;
    }
    if (taken.first != -1) {
      break;
    }
  }
  if (taken.first == -1) {
    exit(0);
  }
  auto [r1, c1] = taken;
  for (auto [r2, c2] : cells) {
    if (marks[r1][c1][r2][c2] == int(cand.size())) {
      --tries;
      if (dig(r2, c2)) {
        return;
      }
      if (!tries) {
        exit(0);
      }
    }
  }
}

signed main() {
  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}