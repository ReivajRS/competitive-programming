#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  multiset<int> st;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = n - 1; j >= 0; j--) {
      if (a[i][j] == 1) cnt++;
      else break;
    }
    st.insert(cnt);
  }
  int mex = 1;
  while (!st.empty()) {
    auto it = st.begin();
    if (*it >= mex) mex++;
    st.erase(it);
  }
  cout << min(mex, n) << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  
  return 0;
}