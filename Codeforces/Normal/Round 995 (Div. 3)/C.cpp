#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
using ll = long long;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(m), q(k);
  for (auto &x : a) cin >> x;
  for (auto &x : q) cin >> x;

  if (k <= n - 2) {
    cout << string(m, '0') << '\n';
    return;
  }

  set<int> st;
  for (int i = 0; i < k; i++) {
    st.insert(q[i]);
  }

  for (int i = 0; i < m; i++) {
    if (k - st.count(a[i]) >= n - 1) {
      cout << '1';
    }
    else {
      cout << '0';
    }
  }
  cout << '\n';
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