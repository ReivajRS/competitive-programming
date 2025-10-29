#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
using ll = long long;

void solve() {
  int n;
  cin >> n;
  int even = 0, odd = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x & 1) odd++;
    else even++;
  }
  cout << odd + (even ? 1 : -1) << '\n';
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