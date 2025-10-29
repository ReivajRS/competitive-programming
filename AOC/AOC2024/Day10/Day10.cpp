#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())

vector<string> mat;
vector<vector<int>> vis;
vector<vector<int>> dp;
int n, m;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void read_input() {
  string s;
  while (cin >> s) {
    mat.push_back(s);
  }
  n = SZ(mat);
  m = SZ(mat[0]);
}

bool is_valid(int i, int j) {
  return i >= 0 && i < n && j >= 0 && j < m;
}

int dfs_cnt = 0;
int cnt = 0;

void dfs(int i, int j) {
  if (mat[i][j] == '9') cnt++;
  vis[i][j] = dfs_cnt;
  for (int k = 0; k < 4; k++) {
    int ii = i + dy[k], jj = j + dx[k];
    if (is_valid(ii, jj) && vis[ii][jj] != dfs_cnt && mat[ii][jj] == mat[i][j] + 1) {
      dfs(ii, jj);
    }
  }
}

int dfs2(int i, int j) {
  if (mat[i][j] == '9') return 1;
  if (vis[i][j] == dfs_cnt) return dp[i][j];
  vis[i][j] = dfs_cnt;
  dp[i][j] = 0;
  for (int k = 0; k < 4; k++) {
    int ii = i + dy[k], jj = j + dx[k];
    if (is_valid(ii, jj) && mat[ii][jj] == mat[i][j] + 1) {
      dp[i][j] += dfs2(ii, jj);
    }
  }
  return dp[i][j];
}

int part1() {
  int ans = 0;

  vis.assign(n + 1, vector<int>(m + 1, -1));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == '0') {
        cnt = 0;
        dfs(i, j);
        ans += cnt;
        dfs_cnt++;
      }
    }
  }

  return ans;
}

int part2() {
  int ans = 0;

  dp.assign(n + 1, vector<int>(m + 1, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == '0') {
        int cnt = dfs2(i, j);
        ans += cnt;
        dfs_cnt++;
      }
    }
  }

  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  read_input();
  cout << "Part 1: " << part1() << '\n';
  cout << "Part 2: " << part2() << '\n';

  return 0;
}