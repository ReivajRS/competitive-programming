#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  
  int idx = -1;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] != 1 && a[i] != -1) {
      idx = i;
    }
  }

  int now_mx = 0, now_mn = 0;
  int mx = 0, mn = 0;
  for (int i = 0; i < n; i++) {
    if (idx == i) {
      now_mn = now_mx = 0;
    }
    else {
      now_mn = min(0, now_mn + a[i]);
      now_mx = max(0, now_mx + a[i]);
    }
    mn = min(mn, now_mn);
    mx = max(mx, now_mx);
  }

  set<int> st;
  for (int i = mn; i <= mx; i++) {
    st.insert(i);
  }

  if (idx == -1) {
    cout << int(st.size()) << '\n';
    for (auto x : st) {
      cout << x << ' ';
    }
    cout << '\n';
    return;
  }

  now_mn = 0, now_mx = 0;
  int mn_l = 0, mn_r = 0, mx_l = 0, mx_r = 0;
  for (int i = idx - 1; i >= 0; i--) {
    now_mn += a[i];
    now_mx += a[i];
    mn_l = min(mn_l, now_mn);
    mx_l = max(mx_l, now_mx);
  }
  now_mn = 0, now_mx = 0;
  for (int i = idx + 1; i < n; i++) {
    now_mn += a[i];
    now_mx += a[i];
    mn_r = min(mn_r, now_mn);
    mx_r = max(mx_r, now_mx);
  }

  for (int i = mn_l + mn_r; i <= mx_l + mx_r; i++) {
    st.insert(a[idx] + i);
  }

  cout << int(st.size()) << '\n';
  for (auto x : st) {
    cout << x << ' ';
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