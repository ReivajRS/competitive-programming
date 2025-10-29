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

int kmp(const string& s, const string& p) {
  string t = p + char(0) + s;
  vector<int> pi = prefix_function(t);
  int n = (int)s.size(), m = (int)p.size();
  int occ = 0;
  for (int i = m + 1; i < n + m + 1; i++) {
    occ += pi[i] == m;
  }
  return occ;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  string s, p;
  cin >> s >> p;

  cout << kmp(s, p) << '\n';

  return 0;
}