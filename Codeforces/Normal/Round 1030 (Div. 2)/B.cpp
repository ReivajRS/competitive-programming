#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
#define SZ(x) ((int)(x).size())

void solve() {
  int n;
  cin >> n;

  vector<tuple<int, int, int>> moves;
  for (int i = 1; i <= n; i++) {
    moves.push_back({i, 1, i});
    if (i + 1 <= n) {
      moves.push_back({i, i + 1, n});
    }
  }

  cout << SZ(moves) << '\n';
  for (auto [x, y, z] : moves) {
    cout << x << ' ' << y << ' ' << z << '\n';
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