#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
vector<string> mat, mat2;
vector<vector<int>> vis, comp;
vector<int> area, sides;
int n, m;

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

int curr_area = 0, curr_perimeter = 0, curr_comp = 0;

void dfs(int i, int j) {
  curr_area++;
  vis[i][j] = 1;
  comp[i][j] = curr_comp;
  for (int k = 0; k < 4; k++) {
    int ii = i + dy[k], jj = j + dx[k];
    if (!is_valid(ii, jj)) {
      curr_perimeter++;
      continue;
    }
    if (mat[ii][jj] != mat[i][j]) {
      curr_perimeter++;
      continue;
    }
    if (!vis[ii][jj]) {
      dfs(ii, jj);
    }
  }
}

int part1() {
  int ans = 0;

  vis.assign(n + 1, vector<int>(m + 1, 0));
  comp.assign(n + 1, vector<int>(m + 1, 0-1));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vis[i][j]) continue;
      curr_area = 0, curr_perimeter = 0;
      dfs(i, j);
      area.push_back(curr_area);
      ans += curr_area * curr_perimeter;
      curr_comp++;
    }
  }

  return ans;
}

int count_corners(int i, int j) {
  char c = mat2[i][j];
  int cnt = 0;
  if (mat2[i - 1][j] != c && mat2[i][j - 1] != c) cnt++;
  if (mat2[i - 1][j] != c && mat2[i][j + 1] != c) cnt++;
  if (mat2[i + 1][j] != c && mat2[i][j + 1] != c) cnt++;
  if (mat2[i + 1][j] != c && mat2[i][j - 1] != c) cnt++;

  if (mat2[i - 1][j] == c && mat2[i][j - 1] == c && mat2[i - 1][j - 1] != c) cnt++;
  if (mat2[i - 1][j] == c && mat2[i][j + 1] == c && mat2[i - 1][j + 1] != c) cnt++;
  if (mat2[i + 1][j] == c && mat2[i][j + 1] == c && mat2[i + 1][j + 1] != c) cnt++;
  if (mat2[i + 1][j] == c && mat2[i][j - 1] == c && mat2[i + 1][j - 1] != c) cnt++;

  return cnt;
}

int part2() {
  int ans = 0;
  
  mat2.push_back(string(m, '#'));
  for (auto s : mat) {
    mat2.push_back("#" + s + "#");
  }
  mat2.push_back(string(m, '#'));

  sides.assign(SZ(area), 0);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      sides[comp[i][j]] += count_corners(i + 1, j + 1);
    }
  }

  for (int i = 0; i < SZ(area); i++) {
    ans += area[i] * sides[i];
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