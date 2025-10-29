#include <bits/stdc++.h>
using namespace std;

using ll = long long;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int q;
  cin >> q;

  list<pair<ll, int>> plants;
  bool ok = true;
  ll time = 0;

  while (q--) {
    int x;
    cin >> x;
    if (x == 1) {
      if (ok) {
        plants.push_back({time, 0});
        ok = false;
      }
      plants.back().second++;
      continue;
    }
    if (x == 2) {
      ll t;
      cin >> t;
      time += t;
      ok = true;
      continue;
    }
    ll h;
    cin >> h;
    ll ans = 0;
    while (!plants.empty() && time - plants.front().first >= h) {
      ans += plants.front().second;
      plants.pop_front();
    }
    cout << ans << '\n';
  }

  return 0;
}