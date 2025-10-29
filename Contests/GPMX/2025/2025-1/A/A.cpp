#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)(x).size())

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  cin >> s;

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string p;
    cin >> p;
    if (SZ(p) % SZ(s) != 0) {
      cout << "No" << '\n';
      continue;
    }
    bool ok = 1;
    for (int j = 0; j < SZ(p); j++) {
      if (s[j % SZ(s)] != p[j]) {
        ok = 0;
        break;
      }
    }
    cout << (ok ? "Yes" : "No") << '\n';
  }
  
  return 0;
}