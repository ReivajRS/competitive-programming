#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  cin >> s;

  int q;
  cin >> q;
  while (q--) {
    ll x;
    cin >> x;
    x--;
    ll blk = x / SZ(s);
    int cnt = __builtin_popcountll(blk);
    char c = s[x % SZ(s)];
    if (cnt % 2 == 0) {
      cout << c << ' ';
      continue;
    }
    cout << (char) (islower(c) ? toupper(c) : tolower(c)) << ' ';
  }

  cout << '\n';

  return 0;
}