#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())

string s, t;
int n, m;
vector<int> p;
vector<vector<int>> dp, aut;

int solve(int i, int j) {
  if (i == n) return 0;
  int& ans = dp[i][j];
  if (ans != -1) return ans;
  ans = 0;
  if (s[i] == '?') {
    if (j + 1 == m) {
      ans = 1 + solve(i + 1, p[m - 1]);
    }
    else {
      for (int c = 0; c < 26; c++) {
        ans = max(ans, solve(i + 1, aut[j][c]));
      }
    }
  }
  else {
    int k = aut[j][s[i] - 'a'];
    bool complete = k == m;
    ans = complete + solve(i + 1, complete ? p[m - 1] : k);
  }
  return ans;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  cin >> s >> t;

  n = SZ(s), m = SZ(t);
  
  aut.assign(m + 1, vector<int>(26, 0));
  dp.assign(n + 1, vector<int>(m + 1, -1));
  p.resize(m);

  for (int i = 1; i < m; i++) {
    int j = p[i - 1];
    while (j > 0 && t[i] != t[j]) {
      j = p[j - 1];
    }
    p[i] = j + (t[i] == t[j]);
  }

  for (int i = 0; i < m; i++) {
    for (int c = 0; c < 26; c++) {
      if (i > 0 && c != t[i] - 'a') {
        aut[i][c] = aut[p[i - 1]][c];
      }
      else {
        aut[i][c] = i + (c == t[i] - 'a');
      }
    }
  }

  cout << solve(0, 0) << '\n';

  return 0;
}