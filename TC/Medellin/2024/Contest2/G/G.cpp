#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'

void solve() {
  int n;
  cin >> n;
  vi a(n);
  for (auto &ai : a) {
    cin >> ai;
  }
  int mm = 1e9, min_found = 1e9, ans = 0;
  FOR (i, 0, n) {
    if (min_found >= a[i]) {
      min_found = min(min_found, a[i]);
      continue;
    }
    if (mm >= a[i]) {
      ans++;
      mm = min(mm, a[i]);
    }
  }
  cout << ans << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}