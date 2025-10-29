#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())

string s;
vector<int> p, ans;
bool ok;
void kmp(char c) {
  s += c;
  p.push_back(0);
  ans.push_back(0);
  ok = 1;
  int i = SZ(s) - 1;
  if (i == 0) return;
  int j = p[i - 1];
  while (j > 0 && c != s[j]) {
    j = p[j - 1];
  }
  p[i] = j + (c == s[j]);
  if (p[i] == 0) return;
  ans[i] = ans[p[i] - 1];
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, e;
  cin >> n >> e;

  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    kmp(c);
  }

  while (e--) {
    int op;
    cin >> op;
    if (op == 1) {
      char c;
      cin >> c;
      kmp(c);
      continue;
    }
    if (op == 2) {
      if (!ok) continue;
      ok = 0;
      ans.back()++;
      continue;
    }
    cout << ans.back() << '\n';
  }

  return 0;
}