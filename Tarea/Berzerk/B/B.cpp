#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 101;
int g[maxn][maxn];

void process_cell(int i, int j) {
  bitset<1001> has;
  for (int k = 1; k < maxn; k++) {
    if (i - k >= 1) has[g[i - k][j]] = 1;
    if (j - k >= 1) has[g[i][j - k]] = 1;
    if (i - k >= 1 && j - k >= 1) has[g[i - k][j - k]] = 1;
  }
  int mex = 0;
  while (has[mex]) mex++;
  g[i][j] = mex;
}

void process_row(int i) {
  for (int j = i + 1; j < maxn; j++) {
    process_cell(i, j);
  }
}

void process_column(int j) {
  for (int i = j + 1; i < maxn; i++) {
    process_cell(i, j);
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  for (int i = 0; i < maxn; i++) {
    g[i][0] = g[0][i] = g[i][i] = 1005;
  }

  for (int idx = 1; idx < maxn; idx++) {
    process_row(idx);
    process_column(idx);
  }

  int nsum = 0;

  while (n--) {
    int i, j;
    cin >> i >> j;
    if (i == j) {
      cout << "Y" << '\n';
      return 0;
    }
    nsum ^= g[i][j];
  }

  cout << (nsum ? "Y" : "N") << '\n';

  return 0;
}