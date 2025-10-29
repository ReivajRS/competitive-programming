#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main() { __
  int n;
  cin >> n;
  
  vector<ll> ps(n + 1, 0), psZ(n + 1, 0);
  FOR(i, 0, n) {
    int x;
    cin >> x;
    ps[i + 1] = ps[i] + x;
    psZ[i + 1] = psZ[i] + (x == 0);
  }

  ll ans = 0;
  FOR (i, 2, n) {
    ll sumR = ps[n] - ps[i], sumL = ps[n] - sumR;
    if (sumR * 2 == sumL) {
      int idx = lower_bound(next(ps.begin()), ps.begin() + i, sumR) - ps.begin();
      int nIdxG = lower_bound(ps.begin(), ps.begin() + i, sumR + 1) - ps.begin();
      int nIdxL = lower_bound(ps.begin(), ps.begin() + i, sumR + 1) - ps.begin();
      if (idx != n + 1 && ps[idx] == sumR) {
        // cout << idx << ' ' << i << ' ' << nIdx - idx << ENDL;
        // ans += max(1ll, psZ[i] - psZ[idx]);
        ans += nIdx - idx;
      }
    }
  }

  cout << ans << ENDL;
  
  return 0;
}