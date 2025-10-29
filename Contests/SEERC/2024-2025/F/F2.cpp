#include <bits/stdc++.h>
using namespace std;

using ll =  long long;
using vi = vector<int>;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

struct FT {
  vector<int> s;
  FT(int n) : s(n + 1) {}
  void update(int pos, int dif) {
    for (; pos < SZ(s); pos |= pos + 1) s[pos] += dif;
  }
  int query(int pos) {
    int res = 0;
    for (; pos > 0; pos &= pos - 1) res += s[pos - 1];
    return res;
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<vi> bags(n);
  vi mn(n), mx(n), values;
  unordered_map<int, int> idxs;
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
      values.push_back(x);
    }
    mn[i] = mini, mx[i] = maxi;
  }

  sort(values.begin(), values.end());
  for (int i = 0; i < SZ(values); i++) {
    idxs[values[i]] = i;
  }

  FT bmn(SZ(values) + 1), bmx(SZ(values) + 1);

  for (int i = 0; i < n; i++) {
    bmn.update(idxs[mn[i]], 1);
    bmx.update(idxs[mx[i]], 1);
  }

  auto check = [&](int i) -> bool {
    bool ok = false;
    if (SZ(bags[i]) == 1) return true;
    int qmn = bmx.query(idxs[mn[i]] + 1);
    int qmx = bmn.query(idxs[mx[i]]);
    for (int j = 0; j < SZ(bags[i]); j++) {
      int l = qmx - bmn.query(idxs[bags[i][j]] + 1);
      int r = bmx.query(idxs[bags[i][j]]) - qmn;
      if (l == 0 && r == 0) {
        ok = true;
        break;
      }
    }
    return ok;
  };

  vi promising;

  for (int i = 0; i < n; i++) {
    if (check(i)) {
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