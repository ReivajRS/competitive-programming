#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ENDL '\n'

using i64 = long long;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    i64 score = 0;
    for (int i = 0; i < n; ++i) {
      score -= a[i];
    }
    for (int i = n; i < 2 * n; ++i) {
      score += a[i];
    }
    cout << score << '\n';
  }

  return 0;
}