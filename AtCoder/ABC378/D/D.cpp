#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
bool vis[11][11];
char mat[11][11];
int n, m, K;

bool is_valid(int i, int j) {
  return i >= 0 && i < n && j >= 0 && j < m && mat[i][j] != '#';
}

int cnt = 0;

void dfs(int i, int j, int k) {
  if (k == 0) {
    cnt++;
    return;
  }
  vis[i][j] = 1;
  for (int l = 0; l < 4; l++) {
    int ii = i + dy[l], jj = j + dx[l];
    if (!is_valid(ii, jj) || vis[ii][jj]) continue;
    dfs(ii, jj, k - 1);
  }
  vis[i][j] = 0;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> m >> K;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
    }
  }

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == '#') continue;
      cnt = 0;
      dfs(i, j, K);
      ans += cnt;
    }
  }

  cout << ans << '\n';

  return 0;
}