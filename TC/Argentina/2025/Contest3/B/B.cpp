#include <bits/stdc++.h>
using namespace std;

using ll = long long;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<ll> l(n), r(n);
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i];
  }
  set<pair<ll, int>> a;
  for (int i = 0; i < m; ++i) {
    ll x;
    cin >> x;
    a.emplace(x, i);
  }

  vector<tuple<ll, ll, int>> ranges;
  for (int i = 0; i < n - 1; ++i) {
    ranges.emplace_back(r[i + 1] - l[i], l[i + 1] - r[i], i);
  }
  sort(ranges.begin(), ranges.end());
  
  vector<int> ans(n - 1);
  for (auto [r, l, pr] : ranges) {
    auto it = a.lower_bound({l, 0});
    if (it == a.end() || get<0>(*it) > r) {
      cout << "No\n";
      return 0;
    }
    ans[pr] = get<1>(*it);
    a.erase(it);
  }
  
  cout << "Yes\n";
  for (int i : ans) {
    cout << i + 1 << ' ';
  }
  cout << '\n';

  return 0;
}