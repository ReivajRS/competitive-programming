#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct XORBasis {
  int LOG, sz = 0;
  vector<ll> basis;
  XORBasis(int LOG) : LOG(LOG), basis(LOG) {}
  void insert(ll x) {
    for (int i = LOG - 1; i >= 0; i--) {
      if (!(x >> i & 1)) {
        continue;
      }
      if (basis[i] == 0) {
        basis[i] = x;
        sz++;
        return;
      }
      x ^= basis[i];
    }
  }
  ll get_max() {
    ll mx = 0;
    for (int i = LOG - 1; i >= 0; i--) {
      if (mx >> i & 1) {
        continue;
      }
      mx ^= basis[i];
    }
    return mx;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int n;
    cin >> n;
    XORBasis xb(63);
    while (n--) {
      ll x;
      cin >> x;
      xb.insert(x);
    }
    cout << "Case " << i << ": " << xb.get_max() << '\n';
  }
  
  return 0;
}
