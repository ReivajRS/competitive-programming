#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int MOD = int(1e9) + 7;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  if (n == 1) {
    cout << a[0][0] << '\n';
    return 0;
  }

  if (n == 2) {
    cout << (a[0][0] == '+' ? 0 : 1) << '\n';
    return 0;
  }

  vector<vector<int>> id(n, vector<int>(n, -1)), action(n, vector<int>(n, -1));
  vector<vector<bool>> vis(n, vector<bool>(n));
  vector<char> op(n * n, '$');

  int cnt = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (vis[i][j]) {
        continue;
      }
      vis[i][j] = true;
      if (a[i][j] != '+' && a[i][j] != '*') {
        continue;
      }
      int ii = i + 1, jj = j + 1;
      while (ii < n && a[ii][j] != a[i][j]) {
        ii++;
      }
      while (jj < n && a[i][jj] != a[i][j]) {
        jj++;
      }
      vis[ii][j] = true;
      vis[i][jj] = true;
      vis[ii][jj] = true;
      for (int j2 = j; j2 <= jj; j2++) {
        action[i][j2] = 0;
        action[ii][j2] = 1;
        id[i][j2] = cnt;
        id[ii][j2] = cnt;
      }
      op[cnt] = a[i][j];
      cnt++;
    }
  }

  vector<stack<int>> st(n);
  vector<vector<int>> parent(n, vector<int>(n, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (action[i][j] == 1) {
        st[j].pop();
      }
      if (!st[j].empty()) {
        parent[i][j] = st[j].top();
      }
      if (action[i][j] == 0) {
        st[j].push(id[i][j]);
      }
    }
  }

  vector<int> val(cnt);
  for (int i = 0; i < cnt; i++) {
    val[i] = op[i] == '+' ? 0 : 1;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!isdigit(a[i][j])) {
        continue;
      }
      if (op[parent[i][j]] == '+') {
        val[parent[i][j]] = (val[parent[i][j]] + int(a[i][j] - '0')) % MOD;
      }
      if (op[parent[i][j]] == '*') {
        val[parent[i][j]] = int(ll(val[parent[i][j]]) * int(a[i][j] - '0') % MOD);
      }
    }
  }
  
  vector<set<int>> g(cnt);
  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < n - 1; j++) {
      if ((a[i][j] == '+' || a[i][j] == '*') && parent[i][j] != -1) {
        g[parent[i][j]].insert(id[i][j]);
      }
    }
  }

  auto dfs = [&](auto& dfs, int u) -> void {
    for (auto v : g[u]) {
      dfs(dfs, v);
      if (op[u] == '+') {
        val[u] = (val[u] + val[v]) % MOD;
      }
      if (op[u] == '*') {
        val[u] = int(ll(val[u]) * val[v] % MOD);
      }
    }
  };

  dfs(dfs, 0);

  cout << val[0] << '\n';
}