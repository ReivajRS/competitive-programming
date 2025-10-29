#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)

signed main() {
  // cin.tie(0)->sync_with_stdio(0);
  
  int t;
  cin >> t;

  while (true) {
    string s;
    cin >> s;
    if (s[0] == 'W' || s[0] == 'L') {
      exit(0);
    }
    int m, b;
    cin >> m >> b;
    if (b * 4 <= m) {
      cout << "PLAY" << endl;
    }
    else {
      cout << "SKIP" << endl;
    }
  }
  
  return 0;
}