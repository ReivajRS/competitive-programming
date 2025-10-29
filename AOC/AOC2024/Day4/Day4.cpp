#include <bits/stdc++.h>
using namespace std;

string target1 = "XMAS", target2 = "MAS";
vector<string> mat;
int n, m;

void read_input() {
  string input;
  while (cin >> input) {
    mat.push_back(input);
  }
  n = (int)mat.size();
  m = (int)mat[0].size();
}

bool check(int i, int j, int di, int dj, int pos, string &target) {
  if (pos == (int)target.size()) return true;
  if (i < 0 || i >= n || j < 0 || j >= m) return false;
  return mat[i][j] == target[pos] && check(i + di, j + dj, di, dj, pos + 1, target);
}

int part1() {
  int ans = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (check(i, j, -1, 0, 0, target1)) ans++;
      if (check(i, j, 0, 1, 0, target1)) ans++;
      if (check(i, j, 1, 0, 0, target1)) ans++;
      if (check(i, j, 0, -1, 0, target1)) ans++;
      if (check(i, j, -1, 1, 0, target1)) ans++;
      if (check(i, j, 1, 1, 0, target1)) ans++;
      if (check(i, j, 1, -1, 0, target1)) ans++;
      if (check(i, j, -1, -1, 0, target1)) ans++;
    }
  }

  return ans;
}

int part2() {
  int ans = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (check(i, j, 1, 1, 0, target2) && check(i + 2, j, -1, 1, 0, target2)) ans++;
      if (check(i, j, 1, 1, 0, target2) && check(i, j + 2, 1, -1, 0, target2)) ans++;
      if (check(i, j + 2, 1, -1, 0, target2) && check(i + 2, j + 2, -1, -1, 0, target2)) ans++;
      if (check(i + 2, j, -1, 1, 0, target2) && check(i + 2, j + 2, -1, -1, 0, target2)) ans++;
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