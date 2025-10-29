#include <bits/stdc++.h>
using namespace std;

struct XORBasis {
  int LOG, sz = 0;
  vector<int> basis;
  XORBasis(int LOG) : LOG(LOG), basis(LOG) {}
  void insert(int x) {
    for (int i = LOG - 1; i >= 0; i--) {
      if (!(x & (1 << i))) {
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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  int total_xor = 0;
  XORBasis xb(30);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    total_xor ^= x;
    xb.insert(x);
  }

  if (total_xor == 0) {
    cout << -1 << '\n';
    return 0;
  }

  cout << xb.sz << '\n';

  return 0;
}