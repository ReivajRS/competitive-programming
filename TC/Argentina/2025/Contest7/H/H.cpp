#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) (int(x.size()))
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<pair<int, int>> p(n);
  for (auto& [x, y] : p) {
    cin >> x >> y;
  }
  sort(p.begin(), p.end());

  cout << "YES\n";
  for (int i = 0; i < n - 1; ++i) {
    cout << p[i].first << ' ' << p[i].second << '\n';
  }

  return 0;
}