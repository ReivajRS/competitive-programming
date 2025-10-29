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
  string a, b;
  cin >> a >> b;

  int n = SZ(a), m = SZ(b);
  int mn = n + m;

  FOR (j, 0, m) {
    int i = 0, cnt = 0;
    int j2 = j;
    while (i < n && j2 < m) {
      if (a[i] == b[j2])
        cnt++, j2++;
      i++;
    }
    mn = min(mn, n + m - cnt);
  }

  cout << mn << ENDL;
}

signed main() { __
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}