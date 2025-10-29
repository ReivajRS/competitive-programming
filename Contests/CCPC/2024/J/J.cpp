#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<tuple<int, int, int>> p(n);
    map<int, int> mpX, mpY, mpZ;
    for (auto &[x, y, z] : p) {
      cin >> x >> y >> z;
      ++mpX[x];
      ++mpY[y];
      ++mpZ[z];
    }

    vector<int> cnt(n);
    for (auto [x, y, z] : p) {
      ++cnt[max({mpX[x], mpY[y], mpZ[z]}) - 1];
    }

    int aux = 0;
    for (int i = 0; i < n; ++i) {
      cout << aux << " \n"[i == n - 1];
      aux += cnt[i];
    }
  }

  return 0;
}