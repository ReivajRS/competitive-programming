#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vi a(n), b(n);
  FOR (i, 0, n) {
    cin >> a[i];
  }
  FOR (i, 0, n) {
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int ans = 0;
  FOR (i, 0, n) {
    int j = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    int mn = 1e9;
    if (j != n) mn = b[j] - a[i];
    if (j != 0) mn = min(mn, a[i] - b[j - 1]);
    ans = max(ans, mn);
  }
  cout << ans << ENDL;

  return 0;
}