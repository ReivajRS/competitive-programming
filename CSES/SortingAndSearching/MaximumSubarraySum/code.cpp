#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  long long cur = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    cur = max(0ll, cur + a[i]);
    ans = max(ans, cur);
  }

  if (ans == 0) {
    ans = *max_element(a.begin(), a.end());
  }

  cout << ans << '\n';
}