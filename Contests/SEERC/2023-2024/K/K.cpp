#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    set<pair<int, int>> deltas;
    for (int i = 1; i <= k; ++i) {
      deltas.insert({0, i});
    }
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; --i) {
      auto it = deltas.begin();
      if (a[i] == -1) {
        it = deltas.end();
        --it;
      }
      auto [f, s] = *it;
      ans[i] = s;
      deltas.erase(it);
      deltas.emplace(f + a[i], s);
    }
    for (int i = 0; i < n; ++i) {
      cout << ans[i] << " \n"[i == n - 1];
    }
  }  

  return 0;
}