#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  priority_queue<int> pq;
  for (int i = 1; i < n; i++) {
    pq.push(a[i] - a[i - 1]);
  }

  int ans = a[n - 1] - a[0];
  while (k > 1 && !pq.empty()) {
    k--;
    ans -= pq.top();
    pq.pop();
  }

  cout << ans << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  tc = 1;

  while (tc--) {
    solve();
  }

  return 0;
}