#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)(x).size())

void solve() {
  /*
    4 3 1

    1, 2
    1, 2
    1, 2
    1, 3


    2 6 1 2 4
    sum = 15

    6 5 5 2
    para grupos de tamaño k
    el máximo tiene que ser divisible entre k
    suma tiene que ser divisible entre k
    suma tiene que ser k * máximo
    tamaño = suma / max
    #grupos = suma / tamaño
    1, 2, 3
    1, 2, 3
    1, 2, 3
    1, 2, 3
    1, 2, 4
    1, 3, 4



    7, 4, 6, 6, 9, 3, 10, 2, 8, 7
    sum = 62
    70 / 10 = 7
    70 / 7 = 10


    2 1 2
    sum = 5

  */

  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  ll sum = 0, mx = 0;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    mx = max(mx, a[i]);
  }
  ll ans = 1;
  for (ll i = 2; i <= n; i++) {
    ll target_sum = i * mx;
    ll x = sum <= target_sum ? target_sum - sum : sum % target_sum;
    if (x <= k) {
      ans = i;
    }
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