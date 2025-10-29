#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, x;
  cin >> n >> x;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&](int i, int j) -> bool {
    return a[i] < a[j];
  });

  int l = 0, r = n - 1;
  while (l < r) {
    if (a[p[l]] + a[p[r]] == x) {
      int i = p[l] + 1, j = p[r] + 1;
      if (i > j) {
        swap(i, j);
      }
      cout << i << ' ' << j << '\n';
      return 0;
    }
    else if (a[p[l]] + a[p[r]] < x) {
      l++;
    }
    else {
      r--;
    }
  }

  cout << "IMPOSSIBLE" << '\n';
}