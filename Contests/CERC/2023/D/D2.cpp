#include <bits/stdc++.h>
using namespace std;

struct sheet {
  int d, fast, slow;
  bool operator<(const sheet& o) const {
    if (slow == o.slow) {
      if (fast == o.fast) {
        return d < o.d;
      }
      return fast < o.fast;
    }
    return slow < o.slow;
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;

  vector<sheet> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].d >> a[i].fast >> a[i].slow;
  }
  sort(a.begin(), a.end());

  vector<int> pref_d(n + 1);
  for (int i = 0; i < n; i++) {
    pref_d[i + 1] = pref_d[i] + a[i].d;
  }

  vector<int> max_fast(n + 1);
  for (int i = n - 1; i >= 0; i--) {
    max_fast[i] = max(max_fast[i + 1], a[i].fast);
  }

  vector<int> min_d(n + 1);
  bitset<300001> dp;
  dp[0] = 1;

  for (int i = 1; i <= n; i++) {
    dp |= dp << a[i - 1].d;
    int L = pref_d[i];
    min_d[i] = (int)dp._Find_next((L + 1) / 2 - 1);
  }

  const int INF = 1e9;

  auto check = [&](int t, int L) -> bool {
    int cnt_slow = (int)(upper_bound(a.begin(), a.end(), sheet{INF, INF, t}) - a.begin());
    if (max_fast[cnt_slow] > t) {
      return false;
    }
    int fast_d = pref_d[n] - pref_d[cnt_slow];
    return min_d[cnt_slow] + fast_d <= L;
  };

  while (q--) {
    int L;
    cin >> L;

    int l = 1, r = INF;
    while (l < r) {
      int m = (l + r) / 2;
      if (check(m, L)) {
        r = m;
      }
      else {
        l = m + 1;
      }
    }

    cout << (check(r, L) ? r : -1) << '\n';
  }

  return 0;
}