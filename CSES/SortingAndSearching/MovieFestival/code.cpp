#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<pair<int, int>> movies(n);
  for (auto& [l, r] : movies) {
    cin >> r >> l;
  }

  sort(movies.begin(), movies.end());

  int ans = 0, last = 0;
  for (auto &[r, l] : movies) {
    if (l >= last) {
      ans++;
      last = r;
    }
  }

  cout << ans << '\n';
}