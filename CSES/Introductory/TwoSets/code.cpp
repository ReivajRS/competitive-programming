#include <bits/stdc++.h>
using namespace std;

using ll = long long;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n;
  cin >> n;

  if ((n * (n + 1) / 2) % 2 != 0) {
    cout << "NO" << '\n';
    return 0;
  }

  cout << "YES" << '\n';
  cout << n / 2 << '\n';

  ll x = n;
  bool flag = 1;
  while (x > 0) {
    cout << x << ' ';
    if (flag) {
      x -= 3;
    }
    else {
      x--;
    }
    flag = !flag;
  }
  cout << '\n';

  cout << (n + 1) / 2 << '\n';
  
  flag = 1;
  x = n - 1;
  
  while (x > 0) {
    cout << x << ' ';
    if (flag) {
      x--;
    }
    else {
      x -= 3;
    }
    flag = !flag;
  }
  cout << '\n';

  return 0;
}