#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<vector<int>> q(n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (i) {
      q[min(i, a[i]) - 1].push_back(i + 1);
    }
  }

  oset<pair<int, int>> ost;
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ost.insert({a[i], i});
    for (int v : q[i]) {
      ans += int(ost.size()) - ost.order_of_key({v, -1});
    }
  }
  cout << ans << '\n';

  return 0;
}