#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    a[i] = c == 'R';
  }

  int round = 0;
  vector<int> vis(n, -1);
  vector<vector<int>> comp(1);

  queue<pair<int, int>> q;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] == 1 && a[i + 1] == 0) {
      q.push({i, 0});
    }
  }

  int moves = 0;
  int level_next_round = -1;

  while (!q.empty()) {
    moves++;
    auto [i, l] = q.front();
    q.pop();
    swap(a[i], a[i + 1]);
    if (l == level_next_round) {
      round++;
      comp.push_back({});
      level_next_round = -1;
    }
    vis[i] = round, vis[i + 1] = round;
    comp[round].push_back(i);
    bool flag = 0;
    if (i > 0 && a[i - 1] == 1 && a[i] == 0) {
      flag |= vis[i - 1] == round;
      flag |= vis[i] == round;
      q.push({i - 1, l + 1});
    }
    if (i + 2 < n && a[i + 1] == 1 && a[i + 2] == 0) {
      flag |= vis[i + 1] == round;
      flag |= vis[i + 2] == round;
      q.push({i + 1, l + 1});
    }
    if (flag) {
      level_next_round = l + 1;
    }
  }

  if (k < round + 1 || k > moves) {
    cout << -1 << '\n';
    return 0;
  }

  bool one = 0;

  for (auto &c : comp) {
    if (one) {
      for (auto &x : c) {
        cout << 1 << ' ' << x + 1 << '\n';
      }
      continue;
    }
    k--;
    if (moves - SZ(c) >= k) {
      moves -= SZ(c);
      cout << SZ(c);
      for (auto &x : c) {
        cout << ' ' << x + 1;
      }
      cout << '\n';
    }
    else {
      int x = moves - k;
      cout << x;
      for (int i = 0; i < x; i++) {
        cout << ' ' << c[i] + 1;
      }
      cout << '\n';
      for (int i = x; i < SZ(c); i++) {
        cout << 1 << ' ' << c[i] + 1 << '\n';
      }
      one = 1;
    }
  }

  return 0;
}