#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)(x).size())

struct Task {
  int d, p, c, lx, rx, ly, ry;
  Task(int d, int p, int c, int lx, int rx, int ly, int ry)
  : d(d), p(p), c(c), lx(lx), rx(rx), ly(ly), ry(ry) {}
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<Task> tasks;
  for (int i = 0; i < n; i++) {
    int d, p, c, lx, rx, ly, ry;
    cin >> d >> p >> c >> lx >> rx >> ly >> ry;
    tasks.push_back({d, p, c, lx, rx, ly, ry});
  }

  vector<double> dp(1 << n);

  for (int mask = 0; mask < (1 << n); mask++) {
    ll t = 0;
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) {
        t += tasks[i].c;
      }
    }
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) {
        continue;
      }
      int nmask = mask | (1 << i);
      ll nt = t + tasks[i].c;
      double avg_value = double(tasks[i].lx + tasks[i].rx) / 2;
      if (nt > tasks[i].d) {
        dp[nmask] = max(dp[nmask], dp[mask]);
        continue;
      }
      if (nt <= tasks[i].ly) {
        dp[nmask] = max(dp[nmask], dp[mask] + tasks[i].p + avg_value);
      }
      else if (nt <= tasks[i].ry) {
        double prob = double(tasks[i].ry - nt) / (tasks[i].ry - tasks[i].ly);
        dp[nmask] = max(dp[nmask], dp[mask] + tasks[i].p + avg_value * prob);
      }
      else {
        dp[nmask] = max(dp[nmask], dp[mask] + tasks[i].p);
      }
    }
  }

  cout << setprecision(12) << fixed;
  cout << dp[(1 << n) - 1] << '\n';
  
  return 0;
}