#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<vector<int>> a(n, vector<int>(n));

  for (int i = 0; i < n; i++) {
    a[i][0] = i;
    a[0][i] = i;
  }

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      vector<int> in(2 * n);
      for (int ii = 0; ii < i; ii++) {
        in[a[ii][j]] = true;
      }
      for (int jj = 0; jj < j; jj++) {
        in[a[i][jj]] = true;
      }
      int mex = 0;
      while (mex < 2 * n && in[mex]) {
        mex++;
      }
      a[i][j] = mex;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[i][j] << ' ';
    }
    cout << '\n';
  }
}