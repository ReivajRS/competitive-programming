#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
using ll = long long;

void solve() {
  ll n, a, b, c;
  cin >> n >> a >> b >> c;
  ll ab = a + b, abc = a + b + c;
  ll ans = 0;
  ans += n / abc * 3;
  n %= abc;
  if (n > 0 && a >= n) {
    ans++;
  }
  else if (n > 0 && ab >= n) {
    ans += 2;
  }
  else if (n > 0 && abc >= n) {
    ans += 3;
  }
  cout << ans << '\n';
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