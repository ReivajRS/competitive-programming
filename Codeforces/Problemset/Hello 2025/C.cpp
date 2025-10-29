#include <bits/stdc++.h>
using namespace std;

void solve() {
  int l, r;
  cin >> l >> r;

  vector<int> num(3);
  num[0] = r;

  int first_one = 0;
  for (int i = 30; i >= 0; i--) {
    if ((num[0] >> i) & 1) {
      first_one = i;
      break;
    }
  }

  for (int i = first_one; i >= 0; i--) {
    if ((num[1] ^ (1 << i)) < r) {
      num[1] ^= (1 << i);
    }
    else if ((num[1] ^ ((1 << i) - 1)) < l) {
      num[1] ^= (1 << i);
    }
  }

  if (num[0] == num[1]) {
    for (int i = 0; i <= first_one; i++) {
      if (((num[1] >> i) & 1) && (num[1] ^ (1 << i)) >= l) {
        num[1] ^= (1 << i);
        break;
      }
    }
  }

  for (int i = first_one; i >= 0; i--) {
    int b0 = (num[0] >> i) & 1, b1 = (num[1] >> i) & 1;
    int sum = b0 + b1;
    if (sum < 2 && (num[2] ^ (1 << i)) < r) {
      num[2] ^= (1 << i);
    }
    else if ((num[2] ^ ((1 << i) - 1)) < l) {
      num[2] ^= (1 << i);
    }
  }

  if (num[1] == num[2]) {
    for (int i = 0; i <= first_one; i++) {
      if (((num[2] >> i) & 1) && (num[2] ^ (1 << i)) >= l) {
        num[2] ^= (1 << i);
        break;
      }
    }
  }

  // 6
  // 30
  // 6
  // 62
  // 30
  // 126
  // 30
  // 2147483646

  int sum = (num[0] ^ num[1]) + (num[0] ^ num[2]) + (num[1] ^ num[2]);
  cout << sum << '\n';
  cout << num[0] << ' ' << num[1] << ' ' << num[2] << '\n';

  bitset<30> bs;
  bs = num[0];
  cout << bs.to_string() << '\n';
  bs = num[1];
  cout << bs.to_string() << '\n';
  bs = num[2];
  cout << bs.to_string() << '\n';
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