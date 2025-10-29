#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve() {
  int x, n;
  cin >> x >> n;

  if (x % n == 0) {
    cout << x/n << ENDL;
    return;
  }

  int ans = 1;
  for (int i = 2; i*i <= x; i++) {
    if (x % i == 0) {
      if (x/i >= n)
        ans = max(ans, i);
      if (i >= n)
        ans = max(ans, x/i);
    }
  }
  cout << ans << ENDL;

}

signed main() { __
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}