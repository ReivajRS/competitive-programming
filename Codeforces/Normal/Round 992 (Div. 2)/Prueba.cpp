#include <bits/stdc++.h>
using namespace std;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n = 5;
  
  vector<int> a;
  for (int i = 1; i <= n ; i++) {
    a.push_back(i);
  }
  vector<pair<int, vector<int>>> perms;
  do {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      int mn = a[i];
      for (int j = i; j < n; j++) {
        mn = min(mn, a[j]);
        sum += mn;
      }
    }
    perms.push_back({-sum, a});
    // for (int i = 0; i < n; i++) {
    //   cout << a[i] << " \n"[i == n - 1];
    // }
    // cout << sum << '\n';
  } while (next_permutation(a.begin(), a.end()));

  sort(perms.begin(), perms.end());
  for (auto [sum, a] : perms) {
    if (sum != perms[0].first) break;
    for (int i = 0; i < n; i++) {
      cout << a[i] << " \n"[i == n - 1];
    }
  }
  
  return 0;
}