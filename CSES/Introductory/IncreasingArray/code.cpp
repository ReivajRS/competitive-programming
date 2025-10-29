#include <bits/stdc++.h>
using namespace std;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  long long ans = 0;
  for (int i = 1; i < n; i++){
    if (a[i - 1] > a[i]) {
      ans += a[i - 1] - a[i];
      a[i] = a[i - 1];
    }
  }

  cout << ans << '\n';
  
  return 0;
}