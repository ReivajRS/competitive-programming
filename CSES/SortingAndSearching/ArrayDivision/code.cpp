#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  auto check = [&](ll x) -> bool {
    ll sum = a[0];
    int cnt = 1;
    for (int i = 1; i < n; i++) {
      if (sum + a[i] > x) {
        cnt++;
        sum = a[i];
      }
      else {
        sum += a[i];
      }
    }
    return cnt <= k;
  };

  ll l = *max_element(a.begin(), a.end()), r = ll(1e18);

  while (l < r) {
    ll m = (l + r) / 2;
    if (check(m)) {
      r = m;
    }
    else {
      l = m + 1;
    }
  }

  cout << l << '\n';
}