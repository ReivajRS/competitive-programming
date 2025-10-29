#include <bits/stdc++.h>
using namespace std;

void solve() {
  int l, r;
  cin >> l >> r;

  vector<int> num(3);
  int x = l ^ r, first_dif = 0;

  for (int i = 30; i >= 0; i--) {
    if ((x >> i)) {
      first_dif = i;
      break;
    }
    else {
      num[0] ^= ((r >> i) & 1) << i;
      num[1] ^= ((r >> i) & 1) << i;
      num[2] ^= ((r >> i) & 1) << i;
    }
  }

  num[0] ^= 1 << first_dif;
  num[1] ^= (1 << first_dif) - 1;
  num[2] = num[0] == r ? l : r;

  cout << num[0] << ' ' << num[1] << ' ' << num[2] << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int tc;
  cin >> tc;

  while (tc--) {
    solve();
  }
  
  return 0;
}