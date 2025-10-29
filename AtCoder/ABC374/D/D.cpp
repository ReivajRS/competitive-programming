#include <bits/stdc++.h>
using namespace std;

int n, t, s;
vector<array<array<int, 2>, 2>> lines;
vector<int> p;

void swap_points(int mask) {
  for (int i = 0; i < n; i++) {
    if ((mask >> i) & 1) {
      swap(lines[p[i]][0], lines[p[i]][1]);
    }
  }
}

double get_seconds(int mask) {
  swap_points(mask);
  double len = hypot(lines[p[0]][0][0], lines[p[0]][0][1]);
  double seconds = len / s;
  for (int i = 0; i < n; i++) {
    len = hypot(lines[p[i]][0][0] - lines[p[i]][1][0], lines[p[i]][0][1] - lines[p[i]][1][1]);
    seconds += len / t;
    if (i + 1 < n) {
      len = hypot(lines[p[i]][1][0] - lines[p[i + 1]][0][0], lines[p[i]][1][1] - lines[p[i + 1]][0][1]);
      seconds += len / s;
    }
  }
  swap_points(mask);
  return seconds;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> s >> t;

  lines.resize(n);

  for (int i = 0; i < n; i++) {
    cin >> lines[i][0][0] >> lines[i][0][1];
    cin >> lines[i][1][0] >> lines[i][1][1];
  }

  p.resize(n);
  iota(p.begin(), p.end(), 0);

  double ans = 1e18;

  do {
    for (int mask = 0; mask < (1 << n); mask++) {
      ans = min(ans, get_seconds(mask));
    }
  } while (next_permutation(p.begin(), p.end()));

  cout << setprecision(8) << fixed;
  cout << ans << '\n';

  return 0;
}