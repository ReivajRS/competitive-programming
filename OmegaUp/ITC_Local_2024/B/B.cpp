#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  int sum1 = 0, sum2 = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int x;
    cin >> x;
    if (s[0] == 't') {
      sum1 += x;
    }
    else {
      sum2 += x;
    }
  }

  if (sum1 == sum2) {
    cout << "nadie debe nada" << '\n';
  }
  else if (sum1 > sum2) {
    cout << "ella " << (sum1 - sum2) / 2 << '\n';
  }
  else {
    cout << "tu " << (sum2 - sum1) / 2 << '\n';
  }

  return 0;
}