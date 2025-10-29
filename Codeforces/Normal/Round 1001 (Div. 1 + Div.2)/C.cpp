#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &x : a) cin >> x;

  auto get_sum = [](vector<ll>& a) -> ll {
    ll sum = 0;
    for (auto &x : a) sum += x;
    return sum;
  };

  auto reduce = [](vector<ll>& a) -> void {
    vector<ll> b;
    for (int i = 0; i < SZ(a) - 1; i++) {
      b.push_back(a[i + 1] - a[i]);
    }
    a = b;
  };

  ll ans = get_sum(a);
  while (SZ(a) > 1) {
    reduce(a);
    ll sum = get_sum(a);
    ans = max({ans, sum, -sum});
  }

  cout << ans << '\n';
  /*
    log(50) ~= 6
    2^6
    2 opciones

    9 7 9 -9 9 -8 7 -8 9
    -2 2 -18 18 -17 15 -15 17
    4 -20 36 -35 32 -30 32

    9 -8 7 -8 9 -9 9 7 9
    -17 15 -15 17 -18 18 -2 2
    -32 30 -32 35 -36 20 4
  */

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