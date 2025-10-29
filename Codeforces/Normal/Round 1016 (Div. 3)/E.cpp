#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)(x).size())

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  set<int> st;
  for (auto &x : a) {
    cin >> x;
    st.insert(x);
  }
  int mex = 0;
  while (st.count(mex)) {
    mex++;
  }
  auto check = [&](int m) -> bool {
    int blk = 0, cnt = 0;
    vector<bool> in(m);
    for (int i = 0; i < n; i++) {
      if (a[i] < m && !in[a[i]]) {
        in[a[i]] = 1;
        cnt++;
      }
      if (cnt == m) {
        in.assign(m, 0);
        cnt = 0;
        blk++;
      }
    }
    return blk >= k;
  };
  int lo = 0, hi = mex;
  while (lo < hi) {
    int m = (lo + hi + 1) >> 1;
    if (check(m)) {
      lo = m;
    }
    else {
      hi = m - 1;
    }
  }

  cout << lo << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int tc;
  cin >> tc;

  while (tc--) {
    solve();
  }
  
  return 0;
}