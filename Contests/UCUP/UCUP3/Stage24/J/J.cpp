#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

constexpr int N = 8, M = 100005;

int n, m;
int rowMask[1 << N][M];
int ans[1 << N];

inline int columnContribution(int mask, int j) {
  int ones = __builtin_popcount(rowMask[mask][j]);
  return min(ones, 1 + n - ones);
}

inline int maskDifference(int mask1, int mask2) {
  return __builtin_popcount(mask1 ^ mask2);
}

int query() {
  int ret = 1e9;
  for (int mask = (1 << n) - 1; mask >= 0; --mask) {
    ret = min(ret, ans[mask]);
  }
  return ret;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int q;
  cin >> n >> m >> q;

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < m; ++j) {
      if (s[j] == '1') {
        rowMask[0][j] |= 1 << i;
      }
    }
  }

  // precalc
  for (int mask = (1 << n) - 1; mask >= 0; --mask) {
    for (int j = 0; j < m; ++j) {
      rowMask[mask][j] = rowMask[0][j] ^ mask;
    }

    ans[mask] = __builtin_popcount(mask);
    for (int j = 0; j < m; ++j) {
      ans[mask] += columnContribution(mask, j);
    }
  }

  cout << query() << '\n';

  int currMask = 0;
  while (q--) {
    char op;
    cin >> op;

    if (op == 'P') {
      int i, j;
      cin >> i >> j;
      --i;
      --j;
      for (int mask = (1 << n) - 1; mask >= 0; --mask) {
        ans[mask] -= columnContribution(mask, j);
        rowMask[mask][j] ^= 1 << i;
        ans[mask] += columnContribution(mask, j);
      }
    } else if (op == 'R') {
      int i;
      cin >> i;
      --i;
      int newMask = currMask ^ (1 << i);
      for (int mask = (1 << n) - 1; mask >= 0; --mask) {
        ans[mask] += maskDifference(mask, newMask) - maskDifference(mask, currMask);
      }
      currMask = newMask;
    } else {
      int j;
      cin >> j;
      --j;
      for (int mask = (1 << n) - 1; mask >= 0; --mask) {
        ans[mask] -= columnContribution(mask, j);
        rowMask[mask][j] = ~rowMask[mask][j] & ((1 << n) - 1);
        ans[mask] += columnContribution(mask, j);
      }
    }
    cout << query() << '\n';
  }

  return 0;
}