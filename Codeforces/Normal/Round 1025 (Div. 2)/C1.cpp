#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
#define SZ(x) ((int)(x).size())

void ask(string s, int& ans) {
  cout << s << endl;
  cin >> ans;
}

void solve() {
  int n;
  cin >> n;
  int ans;
  ask("digit", ans);
  ask("digit", ans);
  ask("add -8", ans);
  ask("add -4", ans);
  ask("add -2", ans);
  ask("add -1", ans);
  ask("add " + to_string(n - 1), ans);
  if (ans == -1) {
    assert(0);
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