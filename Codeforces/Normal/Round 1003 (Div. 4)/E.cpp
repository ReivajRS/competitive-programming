#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
using ll = long long;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  
  if ((k > n && k > m) || abs(n - m) > k) {
    cout << "-1" << '\n';
    return;
  }

  auto construct = [](int n, int m, int k, char c1, char c2) -> string {
    string s = "";
    for (int i = 0; i < k; i++) {
      s += c1;
    }
    n -= k;
    bool turn = 1;
    while (n > 0 && m > 0) {
      if (turn) {
        s += c2;
        m--;
      }
      else {
        s += c1;
        n--;
      }
      turn = !turn;
    }
    if (n > 0) {
      for (int i = 0; i < n; i++) {
        s += c1;
      }
    }
    else {
      for (int i = 0; i < m; i++) {
        s += c2;
      }
    }
    return s;
  };
  
  if (n >= m) {
    cout << construct(n, m, k, '0', '1') << '\n';
  }
  else {
    cout << construct(m, n, k, '1', '0') << '\n';
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  
  return 0;
}