#include <bits/stdc++.h>
using namespace std;

long long f(int i, vector<int>& row, vector<string>& a) {
  if (i == 8) {
    return 1;
  }
  long long cnt = 0;
  for (int j = 0; j < 8; j++) {
    if (a[i][j] == '*') {
      continue;
    }
    bool valid = true;
    for (int ii = 0; ii < i; ii++) {
      if (row[ii] == j || abs(ii - i) == abs(row[ii] - j)) {
        valid = false;
        break;
      }
    }
    if (valid) {
      row[i] = j;
      cnt += f(i + 1, row, a);
      row[i] = -1;
    }
  }
  return cnt;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<string> a(8);
  for (int i = 0; i < 8; i++) {
    cin >> a[i];
  }

  vector<int> row(8, -1);

  cout << f(0, row, a) << '\n';
}