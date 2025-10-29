#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;

  string s, t;
  cin >> s >> t;

  vector<int> comp(n, -1);
  vector<vector<int>> cnt(n, vector<int>(26));

  auto dfs = [&](auto& dfs, int i, int c) -> void {
    comp[i] = c;
    cnt[c][s[i] - 'a']++;
    if (i + k < n && comp[i + k] == -1) {
      dfs(dfs, i + k, c);
    }
    if (i + k + 1 < n && comp[i + k + 1] == -1) {
      dfs(dfs, i + k + 1, c);
    }
    if (i - k >= 0 && comp[i - k] == -1) {
      dfs(dfs, i - k, c);
    }
    if (i - k - 1 >= 0 && comp[i - k - 1] == -1) {
      dfs(dfs, i - k - 1, c);
    }
  };

  int c = 0;
  for (int i = 0; i < n; i++) {
    if (comp[i] == -1) {
      dfs(dfs, i, c++);
    }
  }

  for (int i = 0; i < n; i++) {
    if (cnt[comp[i]][t[i] - 'a'] == 0) {
      cout << "NO" << '\n';
      return;
    }
    cnt[comp[i]][t[i] - 'a']--;
  }

  cout << "YES" << '\n';
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