#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
using ll = long long;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<int> act;
  vector<vector<int>> ans;

  auto f = [&](auto &f, int x, int i) -> void {
    act.push_back(x);
    if (i == n - 1) {
      ans.push_back(act);
      act.pop_back();
      return;
    }
    for (int d = 0; d <= 9; d++) {
      if (x + d + 10 * (n - (i + 1)) > m) break;
      f(f, x + d + 10, i + 1);
    }
    act.pop_back();
  };

  for (int i = 1; i <= 10; i++) {
    f(f, i, 0);
  }

  cout << SZ(ans) << '\n';

  for (auto &v : ans) {
    for (auto &x : v) {
      cout << x << ' ';
    }
    cout << '\n';
  }

  return 0;
}