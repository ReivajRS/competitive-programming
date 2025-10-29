#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n), cnt(3);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }

  vector<int> p(n);
  for (int i = cnt[0]; i < cnt[0] + cnt[1]; i++) {
    p[i] = 1;
  }
  for (int i = cnt[0] + cnt[1]; i < n; i++) {
    p[i] = 2;
  }

  vector<set<int>> pos(3);
  for (int i = 0; i < n; i++) {
    pos[a[i]].insert(i);
  }

  vector<pair<int, int>> moves;

  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == p[i]) {
      pos[a[i]].erase(i);
      continue;
    }
    if (a[i] == 0 && p[i] != 0) {
      int j = *pos[1].begin();
      pos[1].erase(pos[1].begin());
      pos[a[i]].erase(i);
      moves.push_back({j, i});
      a[i]++;
      if (a[i] != p[j]) {
        pos[a[i]].insert(i);
      }
      a[j]--;
      if (a[j] != p[j]) {
        pos[a[j]].insert(j);
      }
    }
    if (a[i] == 1 && p[i] != 1) {
      int j = *pos[2].begin();
      pos[2].erase(pos[2].begin());
      pos[a[i]].erase(i);
      moves.push_back({j, i});
      a[i]++;
      if (a[i] != p[j]) {
        pos[a[i]].insert(i);
      }
      a[j]--;
      if (a[j] != p[j]) {
        pos[a[j]].insert(j);
      }
    }
  }

  cout << int(moves.size()) << '\n';
  for (auto [x, y] : moves) {
    cout << x + 1 << ' ' << y + 1 << '\n';
  }
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