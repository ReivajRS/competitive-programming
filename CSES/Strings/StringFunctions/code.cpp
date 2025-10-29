#include <bits/stdc++.h>
using namespace std;

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
  for (auto &x : z) cout << x << ' ';
  cout << '\n';

  vector<int> p = prefix_function(s);
  for (auto &x : p) cout << x << ' ';
  cout << '\n';

  return 0;
}