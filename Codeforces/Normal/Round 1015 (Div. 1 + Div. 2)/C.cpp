#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  vector<int> c(n + 1, -1);
  int cnt_same = 0;
  for (int i = 0; i < n; i++) {
    if (c[a[i]] == -1 && c[b[i]] == -1) {
      c[a[i]] = b[i];
      c[b[i]] = a[i];
    }
    else if (c[a[i]] != b[i] || c[b[i]] != a[i]) {
      cout << -1 << '\n';
      return;
    }
    if (c[a[i]] == a[i] || c[b[i]] == b[i]) {
      cnt_same++;
    }
  }
  if (cnt_same > 1) {
    cout << -1 << '\n';
    return;
  }

  map<int, map<int, int>> mp;
  for (int i = 0; i < n; i++) {
    mp[a[i]][b[i]] = i;
  }

  auto swap_pos = [&](int i, int j) -> void {
    swap(mp[a[i]][b[i]], mp[a[j]][b[j]]);
    swap(a[i], a[j]);
    swap(b[i], b[j]);
  };

  vector<pair<int, int>> moves;

  if (cnt_same == 1) {
    int m = n / 2;
    for (int i = 0; i < n; i++) {
      if (a[i] == b[i] && i != m) {
        swap_pos(i, m);
        moves.push_back({i, m});
        break;
      }
    }
  }
  
  for (int i = 0; i < n / 2; i++) {
    int ri = n - i - 1;
    int j = mp[b[i]][a[i]];
    if (ri != j) {
      swap_pos(j, ri);
      moves.push_back({j, ri});
    }
  }

  cout << SZ(moves) << '\n';
  for (auto [x, y] : moves) {
    cout << x + 1 << ' ' << y + 1 << '\n';
  }

  // cout << "despues" << '\n';
  // for (int i = 0; i < n; i++) {
  //   cout << a[i] << ' ';
  // }
  // cout << '\n';
  // for (int i = 0; i < n; i++) {
  //   cout << b[i] << ' ';
  // }
  // cout << '\n';
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