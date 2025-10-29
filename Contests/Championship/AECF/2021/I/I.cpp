#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i,a,b) for(int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    int neg = 0, pos = 0, ones = 0;
    ll ans = 0;
    int cnt = 0;
    vi a(n);
    FOR (i, 0, n) {
      cin >> a[i];
    }
    ROF (i, n, 0) {
      if (a[i] == 1) {
        ans += cnt;
        pos++;
        ones++;
        cnt++;
        continue;
      }
      if (a[i] == 0) {
        ans += pos;
        cnt++;
        continue;
      }
      if (a[i] > 0) {
        ans += (cnt - pos + ones);
        pos++;
      }
      if (a[i] < 0) {
        ans += pos;
        neg++;
      }
      cnt++;
    }
    cout << ans << ENDL;
  }

  return 0;
}