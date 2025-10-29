#include <bits/stdc++.h>
using namespace std;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int v1, v2, t, d;
  cin >> v1 >> v2 >> t >> d;

  constexpr int max_speed = 1001;
  vector<int> prev(max_speed, -1e9);
  prev[v1] = v1;

  for (int i = 0; i < t - 1; i++) {
    vector<int> curr(max_speed, -1e9);
    for (int speed = max_speed - 1; speed >= 0; speed--) {
      for (int delta = -d; delta <= d; delta++) {
        if (speed + delta >= 0 && speed + delta < max_speed) {
          curr[speed + delta] = max(curr[speed + delta], prev[speed] + speed + delta);
        }
      }
    }
    prev = curr;
  }

  cout << prev[v2] << '\n';

  return 0;
}