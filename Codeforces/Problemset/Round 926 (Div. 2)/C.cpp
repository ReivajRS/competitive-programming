#include <bits/stdc++.h>
using namespace std;

using ll = long long;

/*
  2 3 15

  1 2 3

  0 1 3

  1 1 3

  -----

  3 3 6

  secuencia tiene que tener longitud x + 1
  j = donde voy
  
  1 2 3 4
  x1, x2, x3, x4
  sum(xi), desde i = 1 hasta i = j - 1
  sum(xi) < xj * (k - 1)
  ganancia = xj * (k - 1) - sum(xi)

  x1 = 1
  x2 = sum(xi)

  xj * (k - 1) = sum(xi)
  xj = sum(xi) + (k - 2) / (k - 1)

  si en algun momento la suma excede a, entonces la respuesta es no
  de no excederse al final la respuesta es si
*/

void solve() {
  ll k, x, a;
  cin >> k >> x >> a;

  vector<ll> b(x + 1);
  b[0] = 1;
  ll sum = b[0];

  for (int i = 1; i <= x; i++) {
    b[i] = sum / (k - 1) + 1;
    sum += b[i];
    if (sum > a) {
      cout << "NO" << '\n';
      return;
    }
  }

  cout << "YES" << '\n';
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