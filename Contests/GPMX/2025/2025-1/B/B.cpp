#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)(x).size())

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

ll dfs(int i, int j, int k, ll sum, vector<vector<int>>& a, vector<vector<int>>& vis, int cnt_dfs, int delta) {
  vis[i][j] = cnt_dfs;
  sum += a[i][j];
  sum = max(0ll, sum);
  int ii = i + dy[k], jj = j + dx[k];
  if (ii < 0 || ii >= SZ(a) || jj < 0 || jj >= SZ(a) || vis[ii][jj] == cnt_dfs) {
    k = (k + delta + 4) % 4;
    ii = i + dy[k], jj = j + dx[k];
  }
  if (ii < 0 || ii >= SZ(a) || jj < 0 || jj >= SZ(a) || vis[ii][jj] == cnt_dfs) {
    return sum;
  }
  return max(sum, dfs(ii, jj, k, sum, a, vis, cnt_dfs, delta));
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  int cnt_dfs = 0;
  vector<vector<int>> vis(n, vector<int>(n, -1));
  ll ans = dfs(0, 0, 1, 0, a, vis, cnt_dfs++, 1);
  ans = max(ans, dfs(0, 0, 2, 0, a, vis, cnt_dfs++, -1));
  ans = max(ans, dfs(0, n - 1, 2, 0, a, vis, cnt_dfs++, 1));
  ans = max(ans, dfs(0, n - 1, 3, 0, a, vis, cnt_dfs++, -1));
  ans = max(ans, dfs(n - 1, 0, 0, 0, a, vis, cnt_dfs++, 1));
  ans = max(ans, dfs(n - 1, 0, 1, 0, a, vis, cnt_dfs++, -1));
  ans = max(ans, dfs(n - 1, n - 1, 3, 0, a, vis, cnt_dfs++, 1));
  ans = max(ans, dfs(n - 1, n - 1, 0, 0, a, vis, cnt_dfs++, -1));

  cout << ans << '\n';
  
  return 0;
}