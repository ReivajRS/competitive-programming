#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())

struct SparseTable {
  vector<vector<int>> jmp;
  void init(const vector<int>& V) {
    if (SZ(jmp)) jmp.clear();
    jmp.emplace_back(V);
    for (int pw = 1, k = 1; pw * 2 <= SZ(V); pw *= 2, k++) {
      jmp.emplace_back(SZ(V) - pw * 2 + 1);
      for (int j = 0; j < SZ(jmp[k]); j++) {
        jmp[k][j] = gcd(jmp[k - 1][j], jmp[k - 1][j + pw]);
      }
    }
  }
  int query(int l, int r) {
    int dep = 31 - __builtin_clz(r - l);
    return gcd(jmp[dep][l], jmp[dep][r - (1 << dep)]);
  }
};

void solve() {
  int n, q;
  cin >> n >> q;

  vector<int> a(n), b(n - 1);
  for (auto &x : a) cin >> x;
  for (int i = 0; i < n - 1; i++) {
    b[i] = abs(a[i + 1] - a[i]);
  }

  SparseTable spt;
  spt.init(b);

  while (q--) {
    int l, r;
    cin >> l >> r;
    if (l == r) {
      cout << 0 << ' ';
      continue;
    }
    cout << spt.query(l - 1, r - 1) << ' ';
  }
  cout << '\n';
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  
  return 0;
}