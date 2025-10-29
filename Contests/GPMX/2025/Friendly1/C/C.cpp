#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<int> a(n);
  int sum = 0;
  int mx = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    mx = max(mx, a[i]);
  }

  if (sum % 2 == 1 || mx > sum - mx) {
    cout << "no" << '\n';
    return 0;
  }

  cout << "yes" << '\n';

  priority_queue<pair<int, int>> pq;
  for (int i = 0; i < n; i++) {
    if (a[i] > 0) {
      pq.push({a[i], i});
    }
  }

  while (SZ(pq) >= 2) {
    auto [x, i] = pq.top();
    pq.pop();
    auto [y, j] = pq.top();
    pq.pop();
    cout << i + 1 << ' ' << j + 1 << '\n';
    if (x - 1 > 0) {
      pq.push({x - 1, i});
    }
    if (y - 1 > 0) {
      pq.push({y - 1, j});
    }
  }
  
  return 0;
}