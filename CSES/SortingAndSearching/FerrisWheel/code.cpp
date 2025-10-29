#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, x;
  cin >> n >> x;

  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }

  sort(p.begin(), p.end());

  int ans = 0, l = 0, r = n - 1;

  while (l < r) {
    if (p[l] + p[r] <= x) {
      l++, r--;
      ans++;
    }
    else {
      r--;
      ans++;
    }
  }

  if (l == r) {
    ans++;
  }

  cout << ans << '\n';
}