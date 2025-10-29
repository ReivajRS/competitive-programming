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
  vector<vi> a(n, vi());
  FOR (i, 0, n) {
    int x;
    cin >> x,
    a[x-1].pb(i);
  }
  FOR (i, 0, n) {
    int cnt = !a[i].empty();
    FOR (j, 1, SZ(a[i])) {
      if ((a[i][j] - a[i][j - 1]) % 2 != 0)
        cnt++;
    }
    cout << cnt << ' ';
  }
  cout << ENDL;
}

signed main() { __
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}