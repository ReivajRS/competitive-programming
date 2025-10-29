#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m, k;
  cin >> n >> m >> k;

  vector<int> a(n), b(m);

  for (auto& x : a) {
    cin >> x;
  }
  for (auto& x : b) {
    cin >> x;
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  auto cmp = [&](int pa, int pb) -> int {
    int l = a[pa] - k, r = a[pa] + k, x = b[pb];
    if (x < l) {
      return -1;
    }
    if (x > r) {
      return 1;
    }
    return 0;
  };

  int pa = 0, pb = 0, ans = 0;
  while (pa < n && pb < m) {
    int side = cmp(pa, pb);
    if (side == -1) {
      pb++;
      continue;
    }
    if (side == 1) {
      pa++;
      continue;
    }
    ans++, pa++, pb++;
  }
  
  cout << ans << '\n';
}