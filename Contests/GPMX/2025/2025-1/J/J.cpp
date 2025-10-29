#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)(x).size())

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<int> a(1 << 26, -1);

  /*
    0000
    0001
    0011
    0010
    0110
    0111
    0101
    0100



    abacxabadabacaba
  */

  // bitset<26> bs;

  int ans = 1;
  int mask = 0;
  for (int i = 0; i < n; i++) {
    int c = s[i] - 'a';
    mask ^= 1 << c;
    int bits = __builtin_popcount(mask);
    if (bits <= 1) {
      ans = i + 1;
    }
    if (a[mask] != -1) {
      ans = max(ans, i - a[mask]);
    }
    for (int j = 0; j < 26; j++) {
      int mask2 = mask ^ (1 << j);
      if (a[mask2] != -1) {
        ans = max(ans, i - a[mask2]);
      }
    }
    if (a[mask] == -1) {
      a[mask] = i;
    }
  }

  cout << ans << '\n';
  
  return 0;
}