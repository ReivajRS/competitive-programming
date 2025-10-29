#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

void solve() {
  int n, on, q;
  cin >> n >> on >> q;
  int c_on = 0;
  int now = on;
  bool flag = (on == n);
  for (int i = 0; i < q; i++) {
    char c;
    cin >> c;
    if (c == '+') {
      c_on++;
      now++;
    }
    else {
      now--;
    }
    if (now == n) {
      flag = 1;
    }
  }
  if (flag) {
    cout << "YES" << '\n';
    return;
  }
  if (on + c_on >= n) {
    cout << "MAYBE" << '\n';
  }
  else {
    cout << "NO" << '\n';
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