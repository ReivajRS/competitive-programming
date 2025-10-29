#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ENDL '\n'

pair<int, int> find_pos(const int W, int x) {
  --x;
  return make_pair(x / W, x % W);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;

  while (t--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (b != a + 1 || d != c + 1 || c < a + 2) {
      cout << -1 << '\n';
      continue;
    }

    const int W = c - a;

    auto [fa,ca] = find_pos(W, a);
    auto [fb,cb] = find_pos(W, b);
    auto [fc,cc] = find_pos(W, c);
    auto [fd,cd] = find_pos(W, d);

    if (fa == fb && cb == ca + 1 && fc == fd && cd == cc + 1 && fc == fa + 1 && ca == cc) {
      cout << 100000 << ' ' << W << '\n';
    } else {
      cout << -1 << '\n';
    }
  }

  return 0;
}