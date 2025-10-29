#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())

vector<string> mat;
vector<vector<bool>> antinode;
unordered_map<char, vector<pair<int, int>>> mp;
unordered_map<char, vector<pair<int, int>>> antinode2;
int n, m;

void read_input() {
  string s;
  while (cin >> s) {
    mat.push_back(s);
  }
  n = (int)mat.size();
  m = (int)mat[0].size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == '.') continue;
      mp[mat[i][j]].push_back({i, j});
    }
  }
}

bool is_valid(int i, int j) {
  return i >= 0 && i < n && j >= 0 && j < m;
}

int part1() {
  int ans = 0;

  antinode.assign(n + 1, vector<bool>(m + 1, false));

  for (auto &[id, a] : mp) {
    for (int i = 0; i < SZ(a); i++) {
      for (int j = i + 1; j < SZ(a); j++) {
        int di = a[i].first - a[j].first, dj = a[i].second - a[j].second;

        int ii = a[i].first + di, jj = a[i].second + dj;
        if (is_valid(ii, jj) && ii != a[j].first && jj != a[j].second) {
          ans += !antinode[ii][jj];
          antinode[ii][jj] = true;
        }
        ii = a[i].first - di, jj = a[i].second - dj;
        if (is_valid(ii, jj) && ii != a[j].first && jj != a[j].second) {
          ans += !antinode[ii][jj];
          antinode[ii][jj] = true;
        }

        ii = a[j].first + di, jj = a[j].second + dj;
        if (is_valid(ii, jj) && ii != a[i].first && jj != a[i].second) {
          ans += !antinode[ii][jj];
          antinode[ii][jj] = true;
        }
        ii = a[j].first - di, jj = a[j].second - dj;
        if (is_valid(ii, jj) && ii != a[i].first && jj != a[i].second) {
          ans += !antinode[ii][jj];
          antinode[ii][jj] = true;
        }

      }
    }
  }

  return ans;
}

int part2() {
  int ans = 0;

  antinode.assign(n + 1, vector<bool>(m + 1, false));

  for (auto &[id, a] : mp) {
    for (int i = 0; i < SZ(a); i++) {
      for (int j = i + 1; j < SZ(a); j++) {
        int di = a[i].first - a[j].first, dj = a[i].second - a[j].second;

        int ii = a[i].first + di, jj = a[i].second + dj;
        while (is_valid(ii, jj)) {
          ans += !antinode[ii][jj];
          antinode[ii][jj] = true;
          if (mat[ii][jj] == '.') mat[ii][jj] = '#';
          ii += di, jj += dj;
        }
        ii = a[i].first - di, jj = a[i].second - dj;
        while (is_valid(ii, jj)) {
          ans += !antinode[ii][jj];
          antinode[ii][jj] = true;
          if (mat[ii][jj] == '.') mat[ii][jj] = '#';
          ii -= di, jj -= dj;
        }

        ii = a[j].first + di, jj = a[j].second + dj;
        while (is_valid(ii, jj)) {
          ans += !antinode[ii][jj];
          antinode[ii][jj] = true;
          if (mat[ii][jj] == '.') mat[ii][jj] = '#';
          ii += di, jj += dj;
        }
        ii = a[j].first - di, jj = a[j].second - dj;
        while (is_valid(ii, jj)) {
          ans += !antinode[ii][jj];
          antinode[ii][jj] = true;
          if (mat[ii][jj] == '.') mat[ii][jj] = '#';
          ii -= di, jj -= dj;
        }

      }
    }
  }

  for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << mat[i][j];
      }
      cout << '\n';
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