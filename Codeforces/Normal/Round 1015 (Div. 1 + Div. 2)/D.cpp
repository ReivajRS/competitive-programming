#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  int mex = min(n - k * m, n / (m + 1));

  int num = 0, gap = max(k, mex);
  vector<int> a(n, -1);
  for (int i = 0; i < n; i++) {
    if (a[i] != -1) {
      break;
    }
    int j = i;
    while (j < n) {
      a[j] = num;
      j += gap;
    }
    num++;
  }

  for (auto x : a) {
    cout << x << ' ';
  }
  cout << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  cin >> tc;

  while (tc--) {
    solve();
  }

  return 0;
}