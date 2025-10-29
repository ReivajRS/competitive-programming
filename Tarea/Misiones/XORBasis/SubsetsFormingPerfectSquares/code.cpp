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

constexpr int MOD = 1e9 + 7;

void solve(int tc) {
  int n;
  cin >> n;
  
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293};
  XORBasis xb(62);

  for (auto x : a) {
    ll mask = 0;
    for (int i = 0; i < 62; i++) {
      while (x % primes[i] == 0) {
        mask ^= 1ll << i;
        x /= primes[i];
      }
    }
    xb.insert(mask);
  }

  int ans = 1;
  for (int i = 0; i < n - xb.sz; i++) {
    ans = ans * 2 % MOD;
  }

  cout << "Case " << tc << ": " << (ans - 1 + MOD) % MOD << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  cin >> tc;
  for (int i = 1; i <= tc; i++) {
    solve(i);
  }

  return 0;
}