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
  
  int n;
  cin >> n;
  XORBasis xb(63);
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    xb.insert(x); 
  }

  cout << xb.get_max() << '\n';
  for (auto x : xb.basis) {
    if (x != 0) {
      cout << x << ' ';
    }
  }
  cout << '\n';
  
  return 0;
}
