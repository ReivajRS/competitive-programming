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
  int n, s, m;
  cin >> n >> s >> m;
  vi l(n), r(n);
  FOR (i, 0, n) {
    cin >> l[i] >> r[i];
  }
  bool can = 0;
  if (s <= l[0]) {
    can = 1;
  }
  FOR (i, 0, n) {
    if (i > 0) {
      can |= (l[i] - r[i - 1] >= s);
    }
  }
  if (m - r[n - 1] >= s) {
    can = 1;
  }
  cout << (can ? "YES" : "NO") << ENDL;
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