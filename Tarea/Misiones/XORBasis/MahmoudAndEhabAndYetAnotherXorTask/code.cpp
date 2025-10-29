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
  bool check(int x) {
    for (int i = LOG - 1; i >= 0; i--) {
      if (!(x >> i & 1)) {
        continue;
      }
      x ^= basis[i];
    }
    return x == 0;
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<vector<pair<int, int>>> queries(n);
  vector<int> ans(q);
  for (int i = 0; i < q; i++) {
    int l, x;
    cin >> l >> x;
    queries[l - 1].push_back({x, i});
  }

  XORBasis xb(25);

  constexpr int MOD = 1e9 + 7;

  vector<int> pow2(n + 1);
  pow2[0] = 1;
  for (int i = 1; i <= n; i++) {
    pow2[i] = pow2[i - 1] * 2 % MOD;
  }

  for (int i = 0; i < n; i++) {
    xb.insert(a[i]);
    for (auto [x, idx] : queries[i]) {
      if (xb.check(x)) {
        ans[idx] = pow2[i + 1 - xb.sz];
      }
    }
  }

  for (auto x : ans) {
    cout << x << '\n';
  }

  return 0;
}