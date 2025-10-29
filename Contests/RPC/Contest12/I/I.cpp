#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using i64 = long long;
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, w;
  cin >> n >> w;
  vector<int> vals;
  vector<tuple<char, int, int, int>> events(n);
  for (int i = 0; i < n; ++i) {
    char op;
    int p;
    cin >> op >> p;
    if (op == '?') {
      vals.push_back(p);
      events[i] = {op, p, -1, -1};
    } else {
      int l, a;
      cin >> l >> a;
      events[i] = {op, p, l, a};
    }
  }
  sort(vals.begin(), vals.end());
  vals.erase(unique(vals.begin(), vals.end()), vals.end());
  auto get = [&](int x) -> int {
    return lower_bound(vals.begin(), vals.end(), x) - vals.begin();
  };
  vector<i64> wave((int)vals.size());
  for (auto [op, p, l, a] : events) {
    if (op == '?') {
      cout << wave[get(p)] << '\n';
      continue;
    }
    for (int i = 0; i < (int)vals.size(); ++i) {
      if (vals[i] < p || vals[i] >= p + l) {
        continue;
      }
      if (vals[i] % 4 == p % 4) {
        wave[i] += a;
      } else if (vals[i] % 4 == (p + 2) % 4) {
        wave[i] -= a;
      }
    }
  }
  return 0;
}