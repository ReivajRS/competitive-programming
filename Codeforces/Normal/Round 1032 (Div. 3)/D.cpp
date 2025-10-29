#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
#define SZ(x) ((int)(x).size())

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
  vector<pair<int, int>> moves;
  for (int i = 0; i < n; i++) {
    if (a[i] > b[i]) {
      swap(a[i], b[i]);
      moves.push_back({3, i});
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (a[j] > a[j + 1]) {
        swap(a[j], a[j + 1]);
        moves.push_back({1, j});
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (b[j] > b[j + 1]) {
        swap(b[j], b[j + 1]);
        moves.push_back({2, j});
      }
    }
  }
  cout << SZ(moves) << '\n';
  for (auto [x, y] : moves) {
    cout << x << ' ' << y + 1 << '\n';
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