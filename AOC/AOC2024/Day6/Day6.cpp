#include <bits/stdc++.h>
using namespace std;

vector<string> mat;
vector<vector<bool>> vis;
vector<vector<vector<int>>> vis2;
int n, m;
pair<int, int> start;
int dir;

unordered_map<char, int> dx = {{'^', 0}, {'>', 1}, {'v', 0}, {'<', -1}};
unordered_map<char, int> dy = {{'^', -1}, {'>', 0}, {'v', 1}, {'<', 0}};
vector<char> dirs = {'^', '>', 'v', '<'};

void read_input() {
  string s;
  while (cin >> s) {
    mat.push_back(s);
  }
  n = (int)mat.size();
  m = (int)mat[0].size();
  vis.assign(n, vector<bool>(m));
  vis2.assign(n, vector<vector<int>>(m, vector<int>(4, -1)));
}

bool is_valid(int i, int j) {
  return i >= 0 && i < n && j >= 0 && j < m;
}

int cnt = 0;
void dfs(int i, int j, int k) {
  cnt += !vis[i][j];
  vis[i][j] = true;
  int ii = i + dy[dirs[k]], jj = j + dx[dirs[k]];
  if (ii < 0 || ii >= n || jj < 0 || jj >= m) {
    return;
  }
  if (mat[ii][jj] == '#') {
    k = (k + 1) % (int)dirs.size();
    dfs(i, j, k);
  }
  else {
    dfs(ii, jj, k);
  }
}

int cnt_dfs = 0;
bool dfs2(int i, int j, int k) {
  if (vis2[i][j][k] == cnt_dfs) {
    return true;
  }
  vis2[i][j][k] = cnt_dfs;
  int ii = i + dy[dirs[k]], jj = j + dx[dirs[k]];
  if (!is_valid(ii, jj)) {
    return false;
  }
  if (mat[ii][jj] == '#') {
    k = (k + 1) % (int)dirs.size();
    if (dfs2(i, j, k)) {
      return true;
    }
  }
  else {
    if (dfs2(ii, jj, k)) {
      return true;
    }
  }
  return false;
}

int part1() {
  int ans = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (dx.count(mat[i][j])) {
        start = {i, j};
      }
    }
  }

  auto [i, j] = start;
  for (int k = 0; k < (int)dirs.size(); k++) {
    if (dirs[k] == mat[i][j]) {
      dir = k;
      dfs(i, j, k);
      break;
    }
  }

  ans = cnt;

  return ans;
}

int part2() {
  int ans = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == '.' && vis[i][j]) {
        mat[i][j] = '#';
        ans += dfs2(start.first, start.second, dir);
        cnt_dfs++;
        mat[i][j] = '.';
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