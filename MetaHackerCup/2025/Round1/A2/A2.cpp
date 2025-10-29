#include <bits/stdc++.h>
using namespace std;

void solve(int t) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  auto check = [&](int x) -> bool {
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n; i++) {
      if (x >= a[i]) {
        g[n].push_back(i);
        g[i].push_back(n);
      }
    }
    for (int i = 0; i < n - 1; i++) {
      if (x >= abs(a[i + 1] - a[i])) {
        g[i].push_back(i + 1);
        g[i + 1].push_back(i);
      }
    }
    vector<bool> vis(n + 1);
    queue<int> q;
    q.push(n);
    vis[n] = true;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto v : g[u]) {
        if (!vis[v]) {
          vis[v] = true;
          q.push(v);
        }
      }
    }
    return int(count(vis.begin(), vis.end(), false)) == 0;
  };
  int l = 1, r = int(1e9);
  while (l < r) {
    int m = (l + r) / 2;
    if (check(m)) {
      r = m;
    }
    else {
      l = m + 1;
    }
  }
  cout << "Case #" << t << ": " << l << '\n';
}

int main() {
  // cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    solve(i);
  }
}