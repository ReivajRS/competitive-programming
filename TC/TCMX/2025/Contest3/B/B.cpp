#include <bits/stdc++.h>
using namespace std;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int N, T, A0, X, Y;
  cin >> N >> T >> A0 >> X >> Y;

  vector<int> taps;

  for (int i = 0; i < T; i++) {
    int x;
    cin >> x;
    taps.push_back(x);
  }

  int sum = 0, val = A0;

  vector<int> vis(X, -2);
  vis[0] = -1;

  int pos = 0;
  while (true) {
    (sum += val) %= X;
    if (vis[sum] != -2 && pos - vis[sum] >= Y) {
      cout << vis[sum] + 1 << ' ' << pos << '\n';
      return 0;
    }
    if (vis[sum] == -2) {
      vis[sum] = pos;
    }
    bool on = 0;
    for (int i : taps) {
      on ^= (val >> i) & 1;
    }
    val >>= 1;
    if (on) {
      val |= (1 << (N - 1));
    }
    pos++;
  }

  return 0;
}