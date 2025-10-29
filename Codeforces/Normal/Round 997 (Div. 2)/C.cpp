#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  cout << "1 1 2 3 ";
  int last = 3;
  n -= 6;
  while (n--) {
    cout << (++last) << ' ';
  }
  cout << "1 2" << '\n';
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