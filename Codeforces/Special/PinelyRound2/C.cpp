#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

void solve() {
  int n, k;
  cin >> n >> k;

  deque<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<bool> in(n + 1);
  for (int i = 0; i < n; i++) {
    in[a[i]] = 1;
  }
  int mex;
  for (int i = 0; i <= n; i++) {
    if (!in[i]) {
      mex = i;
      break;
    }
  }
  k %= (n + 1);
  for (int i = 0; i < k; i++) {
    a.push_front(mex);
    mex = a.back();
    a.pop_back();
  }

  for (auto &x : a) {
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