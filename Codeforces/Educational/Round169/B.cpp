#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

void solve() {
  vector<pi> a(2);
  cin >> a[0].first >> a[0].second;
  cin >> a[1].first >> a[1].second;
  sort(ALL(a));
  if (a[0].second < a[1].first) {
    cout << 1 << ENDL;
    return;
  }
  if (a[0] == a[1]) {
    cout << a[0].second - a[0].first << ENDL;
    return;
  }
  int cnt = min(a[0].second, a[1].second) - max(a[0].first, a[1].first) + 1;
  if (a[0].first != a[1].first && a[0].second != a[1].second) {
    cnt++;
  }
  cout << cnt << ENDL;
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