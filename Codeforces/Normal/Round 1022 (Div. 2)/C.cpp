#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)(x).size())

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, vector<int>> mp;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]].push_back(i);
  }
  for (auto &[k, v] : mp) {
    sort(v.begin(), v.end());
  }
  vector<bool> active(n, 1);
  int ans = 0;
  for (auto it = mp.rbegin(); it != mp.rend(); it++) {
    vector<int> &v = it->second;
    int l = 0, r = 0;
    while (l < SZ(v)) {
      while (r + 1 < SZ(v) && v[r] + 1 == v[r + 1]) {
        r++;
      }
      for (int i = v[l]; i <= v[r]; i++) {
        active[i] = 0;
      }
      if ((v[l] - 1 >= 0 && !active[v[l] - 1]) || (v[r] + 1 < n && !active[v[r] + 1])) {
        l = r + 1, r = l;
        continue;
      }
      ans++;
      l = r + 1, r = l;
    }
  }
  cout << ans << '\n';
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