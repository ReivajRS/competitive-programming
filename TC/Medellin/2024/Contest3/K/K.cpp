#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a - 1; i >= b; i--)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n, m;
  cin >> n >> m;

  vi a(n);
  FOR (i, 0, n) {
    cin >> a[i];
  }

  auto get_sums = [&](int l, int r) -> vi {
    int len = r - l + 1;
    vi ret;
    for (int i = 0; i < (1 << len); i++) {
      int sum = 0;
      for (int j = 0; j < len; j++) {
        if (i & (1 << j)) {
          sum += a[l + j];
          sum %= m;
        }
      }
      ret.pb(sum);
    }
    return ret;
  };

  vi l = get_sums(0, n / 2 - 1);
  vi r = get_sums(n / 2, n - 1);
  
  sort(ALL(l));
  sort(ALL(r));

  int ans = 0;
  FOR (i, 0, SZ(l)) {
    auto idx = lower_bound(ALL(r), m - l[i]);
    if (idx != r.begin())
      ans = max(ans, l[i] + r[idx - r.begin() - 1]);
  }

  cout << ans << ENDL;

  return 0;
}