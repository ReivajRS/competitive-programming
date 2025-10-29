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
  int n;
  int l, r;
  cin >> n >> l >> r;

  vector<ll> ps(n + 1, 0);
  FOR (i, 0, n) {
    int x;
    cin >> x;
    ps[i + 1] = ps[i] + x;
  }

  int ans = 0, lb = 0, rb = 0;
  FOR (i, 0, n) {
    rb++;
    while (lb < rb) {
      ll sum = ps[rb] - ps[lb];
      if (sum >= l && sum <= r) {
        ans++;
        lb = rb;
        break;
      }
      if (sum < l)
        break;
      lb++;
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