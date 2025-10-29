#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> prefix_function(const string& s) {
  int n = (int)s.size();
  vector<int> p(n);
  for (int i = 1; i < n; i++) {
    int j = p[i - 1];
    while (j > 0 && s[i] != s[j]) {
      j = p[j - 1];
    }
    p[i] = j + (s[i] == s[j]);
  }
  return p;
}

constexpr ll mod = 1e9 + 7;
ll dp[1001][101];

ll solve(int i, int j, const string& s, const vector<int>& pi, const int& n, const int& m) {
  if (i == n) return j == m;
  ll& ans = dp[i][j];
  if (ans != -1) return ans;
  if (j == m) return ans = solve(i + 1, j, s, pi, n, m) * 26 % mod;
  ans = 0;
  for (int c = 0; c < 26; c++) {
    int k = j;
    while (k > 0 && c != s[k] - 'A') {
      k = pi[k - 1];
    }
    k += (c == s[k] - 'A');
    ans += solve(i + 1, k, s, pi, n, m);
    ans %= mod;
  }
  return ans;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  string s;
  cin >> s;

  int m = (int)s.size();
  vector<int> pi = prefix_function(s);
  memset(dp, -1, sizeof dp);

  cout << solve(0, 0, s, pi, n, m) << '\n';

  return 0;
}