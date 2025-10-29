#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int ones = 0;
  for (char c : s) {
    ones += c == '1';
  }
  if (ones <= k) {
    cout << "Alice" << '\n';
    return;
  }
  if (k == 1) {
    cout << "Bob" << '\n';
    return;
  }
  cout << (k > n / 2 ? "Alice" : "Bob") << '\n';
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