#include <bits/stdc++.h>
using namespace std;

using ll = long long;

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

constexpr int MOD = 1e9 + 7;

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};

  XORBasis xb(20);

  for (auto x : a) {
    int mask = 0;
    for (int i = 0; i < 19; i++) {
      while (x % primes[i] == 0) {
        mask ^= 1 << i;
        x /= primes[i];
      }
    }
    xb.insert(mask);
  }

  int ans = 1;
  for (int i = 0; i < n - xb.sz; i++) {
    ans = ans * 2 % MOD;
  }

  cout << (ans - 1 + MOD) % MOD << '\n';

  return 0;
}