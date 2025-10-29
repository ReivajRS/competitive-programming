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

void solve() {
  int n;
  cin >> n;
  vi a(n);
  int fc = -1, lc = -1;
  FOR (i, 0, n) {
    cin >> a[i];
    if (a[i] == 1 && fc == -1)
      fc = i;
    if (a[i] == 1 && fc != -1)
      lc = i;
  }
  int cnt = 0;
  FOR (i, fc, lc)
    if (a[i] == 0)
      cnt++;
  cout << cnt << ENDL;
}

signed main() { __
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}