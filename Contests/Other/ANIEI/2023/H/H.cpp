#include <bits/stdc++.h>
using namespace std;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  cin >> s;

  bool player = s == "Bruce";

  int A, B, C, Q;
  cin >> A >> B >> C >> Q;

  const int maxn = 1e6 + 1;
  vector<int> g(maxn);
  vector<int> has(maxn);

  for (int i = 0; i < maxn; i++) {
    for (int j = 0; j <= 2; j++) {
      if (!((has[i] >> j) & 1)) break;
      g[i]++;
    }
    if (i + A < maxn) has[i + A] |= (1 << g[i]);
    if (i + B < maxn) has[i + B] |= (1 << g[i]);
    if (i + C < maxn) has[i + C] |= (1 << g[i]);
  }

  while (Q--) {
    int k;
    cin >> k;
    int nsum = 0;
    for (int i = 0; i < k; i++) {
      int x;
      cin >> x;
      nsum ^= g[x];
    }
    if (player) {
      cout << (nsum ? "Happy Bruce" : "Sad Arthur") << '\n';
    }
    else {
      cout << (!nsum ? "Happy Bruce" : "Sad Arthur") << '\n';
    }
  }

  return 0;
}