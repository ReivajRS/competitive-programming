#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> card(n * m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      card[x] = i;
    }
  }
  if (n == 1) {
    cout << 1 << '\n';
    return;
  }
  vector<int> order;
  vector<int> pos(n, -1);
  for (int x = 0; x < n * m; x++) {
    int cow = card[x];
    if (pos[cow] != -1) break;
    pos[cow] = SZ(order);
    order.push_back(cow);
  }
  for (int x = 0; x < n * m; x++) {
    int p = x % SZ(order);
    if (x > 0 && card[x] == card[x - 1]) {
      cout << -1 << '\n';
      return;
    }
    if (x + 1 < n * m && card[x] == card[x + 1]) {
      cout << -1 << '\n';
      return;
    }
    if (card[x] != order[p]) {
      cout << -1 << '\n';
    }
  }
  for (auto &x : order) {
    cout << x + 1 << ' ';
  }
  cout << '\n';
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