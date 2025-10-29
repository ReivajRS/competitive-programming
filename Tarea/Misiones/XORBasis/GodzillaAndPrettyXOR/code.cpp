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
  int get_kth(int k) {
    int x = 0;
    int rem = 1 << sz;
    for (int i = LOG - 1; i >= 0; i--) {
      if (basis[i] == 0) {
        continue;
      }
      int half = rem / 2;
      if (k > half) {
        k -= half;
        if (!(x >> i & 1)) {
          x ^= basis[i];
        }
      }
      else if ((x >> i & 1)) {
          x ^= basis[i];
        }
      rem /= 2;
    }
    return x;
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  XORBasis xb(30);

  for (int i = 0; i < n; i++) {
    int t, k;
    cin >> t >> k;
    if (t == 1) {
      xb.insert(k);
    }
    else {
      cout << xb.get_kth(k) << '\n';
    }
  }

  return 0;
}