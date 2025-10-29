#include <bits/stdc++.h>
using namespace std;

using ll =  long long;
using vi = vector<int>;

#define SZ(x) ((int)x.size())

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<vi> bags(n);
  vi mn(n), mx(n);
  vi lv, rv;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    int mini = 1e9 + 5, maxi = -1;
    while (k--) {
      int x;
      cin >> x;
      bags[i].push_back(x);
      mini = min(mini, x);
      maxi = max(maxi, x);
    }
    mn[i] = mini, mx[i] = maxi;
    lv.push_back(mn[i]);
    rv.push_back(mx[i]);
  }

  sort(lv.begin(), lv.end());
  sort(rv.begin(), rv.end());

  auto check = [&](int i) -> bool {
    bool ok = false;
    if (SZ(bags[i]) == 1) return true;
    for (int j = 0; j < SZ(bags[i]); j++) {
      int l = lower_bound(lv.begin(), lv.end(), mx[i]) - lower_bound(lv.begin(), lv.end(), bags[i][j] + 1);
      int r = lower_bound(rv.begin(), rv.end(), bags[i][j]) - lower_bound(rv.begin(), rv.end(), mn[i] + 1);
      cout << bags[i][j] << '\n';
      cout << l << ' ' << r << '\n';
      if (l <= 0 && r <= 0) {
        ok = true;
        break;
      }
    }
    return ok;
  };

  vi promising;

  for (int i = 0; i < n; i++) {
    if (check(i)) {
      cout << "bueno " << i << '\n';
      promising.push_back(i);
    }
  }

  vector<pair<int, int>> segments;
  for (auto x : promising) {
    segments.push_back({mn[x], mx[x]});
  }

  sort(segments.begin(), segments.end(), [&](pair<int, int> i, pair<int, int> j) -> bool {
    return i.second < j.second;
  });

  int pick_cnt = 0;
  int last_r = -1;
  for (int i = 0; i < SZ(segments); i++) {
    if (last_r < segments[i].first) {
      pick_cnt++;
      last_r = segments[i].second;
    }
  }

  cout << 2 * n - pick_cnt << '\n';

  return 0;
}