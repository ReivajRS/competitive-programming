#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<bool> dead(n);
  int ans = 0;
  for (int j = 31; j >= 0; j--) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (dead[i]) continue;
      cnt += ((a[i] >> j) & 1);
    }
    if (cnt < k) continue;
    ans |= (1 << j);
    for (int i = 0; i < n; i++) {
      if (dead[i]) continue;
      dead[i] = !((a[i] >> j) & 1);
    }
  }

  cout << ans << '\n';

  return 0;
}