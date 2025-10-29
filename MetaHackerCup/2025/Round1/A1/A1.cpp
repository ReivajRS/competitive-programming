#include <bits/stdc++.h>
using namespace std;

void solve(int t) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    ans = max(ans, abs(a[i + 1] - a[i]));
  }
  cout << "Case #" << t << ": " << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    solve(i);
  }
}