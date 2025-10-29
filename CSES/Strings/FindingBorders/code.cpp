#include <bits/stdc++.h>
using namespace std;

vector<int> z_function(const string& s) {
  int n = (int)s.size();
  vector<int> z(n);
  int l = 0, r = 0;
  for (int i = 1; i < n; i++) {
    z[i] = max(0, min(z[i - l], r - i));
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
    if (i + z[i] > r) {
      l = i, r = i + z[i];
    }
  }
  return z;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  cin >> s;

  vector<int> z = z_function(s);
  int n = (int)s.size();
  for (int i = n - 1; i >= 1; i--) {
    if (i + z[i] == n) {
      cout << z[i] << ' ';
    }
  }
  cout << '\n';

  return 0;
}