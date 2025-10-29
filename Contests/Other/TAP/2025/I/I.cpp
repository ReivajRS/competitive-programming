#include <bits/stdc++.h>
using namespace std;

using ll = long long;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<int> val(n + 1);

  while (m--) {
    int x, y;
    cin >> x >> y;
    vector<int> a(n);
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 1) {
        cnt1++;
      }
    }
    int op1 = x / (cnt1 + 1);
    int op2 = y;
    if (op1 >= op2) {
      for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
          val[i] += op1;
        }
        else {
          val[i] += op2;
        }
      }
      val[n] += op1;
    }
    else {
      if (cnt1 == 0) {
        op1 = 0;
      }
      else {
        op1 = x / cnt1;
      }
      for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
          val[i] += op1;
        }
        else {
          val[i] += op2;
        }
      }
      val[n] += op2;
    }
  }

  for (int i = 0; i <= n; i++) {
    cout << val[i] << ' ';
  }
  cout << '\n';
}