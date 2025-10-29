#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  ll total = accumulate(a.begin(), a.end(), 0ll);
  ll ans = total;

  for (int mask = 0; mask < (1 << n); mask++) {
    ll sum = 0;
    for (int i = 0; i < n; i++) {
      if ((mask >> i) & 1) {
        sum += a[i];
      }
    }
    ans = min(ans, abs(sum - (total - sum)));
  }

  cout << ans << '\n';
}