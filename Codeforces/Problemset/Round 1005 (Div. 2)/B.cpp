#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> cnt(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  pair<int, int> ans = {-1, -1};
  int mxlen = -1;
  int l = - 1, r = -1;
  int i = 0;
  while (i < n) {
    if (cnt[a[i]] == 1) {
      l = i, r = i;
      i++;
      while (i < n && cnt[a[i]] == 1) {
        i++;
        r++;
      }
      if (r - l > mxlen) {
        mxlen = r - l;
        ans = {l, r};
      }
    }
    else {
      i++;
    }
  }
  if (mxlen == -1) {
    cout << 0 << '\n';
    return;
  }
  cout << ans.first + 1 << ' ' << ans.second + 1 << '\n';
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