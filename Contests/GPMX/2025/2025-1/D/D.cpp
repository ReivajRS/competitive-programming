#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)(x).size())

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int k;
  cin >> k;

  vector<ll> a(k);
  for (int i = 0; i < k; i++) {
    cin >> a[i];
  }

  int n;
  cin >> n;
  vector<vector<ll>> b(n, vector<ll>(k));
  vector<ll> sums(k);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      cin >> b[i][j];
      sums[j] += b[i][j];
    }
  }

  ll day = 1e18;
  for (int i = 0; i < k; i++) {
    if (sums[i] == 0) {
      continue;
    }
    day = min(day, a[i] / sums[i]);
  }

  for (int i = 0; i < k; i++) {
    a[i] -= day * sums[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      a[j] -= b[i][j];
      if (a[j] < 0) {
        cout << day + 1 << ' ' << i + 1 << '\n';
        return 0;
      }
    }
  }
  
  return 0;
}