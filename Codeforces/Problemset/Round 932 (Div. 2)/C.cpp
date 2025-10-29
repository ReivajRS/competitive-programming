#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

void solve() {
  int n, l;
  cin >> n >> l;

  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }

  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&](int i, int j) -> bool {
    if (b[i] == b[j]) {
      return a[i] < a[j];
    }
    return b[i] < b[j];
  });

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ll sum = a[p[i]];
    if (sum <= l) {
      ans = max(ans, 1);
    }
    set<pair<int, int>> st;
    set<int> st_r;
    for (int j = i + 1; j < n; j++) {
      sum += a[p[j]];
      st.insert({a[p[j]], p[j]});
      st_r.insert(p[j]);
      int dif = b[p[j]] - b[p[i]];
      while (sum + dif > l && SZ(st) > 1) {
        auto it = prev(st.end());
        sum -= it->first;
        st_r.erase(it->second);
        st.erase(it);
        dif = b[*st_r.rbegin()] - b[p[i]];
      }
      if (sum + dif <= l) {
        ans = max(ans, SZ(st) + 1);
      }
    }
  }

  cout << ans << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}