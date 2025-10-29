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

  ll total = 1;
  for (int i = 0; i < xb.sz; i++) {
    total *= 2;
  }

  cout << total - n << '\n';
  
  return 0;
}
