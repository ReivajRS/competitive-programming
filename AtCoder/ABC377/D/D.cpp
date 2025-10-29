#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
using ll =  long long;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }

  sort(a.begin(), a.end(), [](const pair<int, int> &i, const pair<int, int> &j) -> bool {
    return i.second < j.second;
  });

  ll ans = 0;
  int idx = 0, l = 1;
  for (int r = 1; r <= m; r++) {
    while (idx < n && a[idx].second == r) {
      l = max(l, a[idx].first + 1);
      idx++;
    }
    ans += r - l + 1;
  }

  cout << ans << '\n';

  return 0;
}