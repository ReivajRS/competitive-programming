#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

signed main() {
  int n;
  cin >> n;
  ll cnt = 0, puntos = 0;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    if (x == 1) {
      cnt++;
      puntos++;
      if (cnt >= 3)
        puntos++;
    }else {
      cnt = 0;
      puntos--;
    }
  }
  cout << puntos << '\n';
}