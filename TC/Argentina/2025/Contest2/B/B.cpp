#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  cin >> s;

  int h = 0, v = 0;
  for (char c : s) {
    if (c == '1') {
      cout << 1 << ' ' << (!h ? 1 : 3) << '\n';
      h = (h + 1) % 2;
    } else {
      cout << 3 << ' ' << v + 1 << '\n';
      v = (v + 1) % 4;
    }
  }

  return 0;
}