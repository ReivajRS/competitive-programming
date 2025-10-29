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
  int sum = 0;
  ROF (i, n + 1, 1) {
    sum += i * (i * 2 - 1);
  }
  cout << sum << ' ' << 2 * n << ENDL;
  ROF (i, n + 1, 1) {
    cout << 1 << ' ' << i << ' ';
    FOR (j, 1, n + 1)
      cout << j << ' ';
    cout << ENDL;
    cout << 2 << ' ' << i << ' ';
    FOR (j, 1, n + 1)
      cout << j << ' ';
    cout << ENDL;
  }
}

signed main() { __
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}