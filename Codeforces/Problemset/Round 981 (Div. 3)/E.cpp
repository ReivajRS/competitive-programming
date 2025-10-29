#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> p(n), pos(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
    pos[p[i]] = i;
  }
  
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (p[i] == i || p[p[i]] == i) {
      continue;
    }
    cnt++;
    int j = pos[p[p[i]]], k = pos[i];
    swap(pos[p[j]], pos[p[k]]);
    swap(p[j], p[k]);
  }

  cout << cnt << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  cin >> tc;

  while (tc--) {
    solve();
  }
  
  return 0;
}