#include <bits/stdc++.h>
using namespace std;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  long long n;
  cin >> n;

  cout << n;
  while (n != 1) {
    if (n & 1) {
      n = n * 3 + 1;
    }
    else {
      n /= 2;
    }
    cout << ' ' << n;
  }
  cout << '\n';

  return 0;
}