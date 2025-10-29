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
  int n;
  cin >> n;
  vi b(n - 1);
  for (auto &x : b) {
    cin >> x;
  }
  vi a = {b[0]};
  FOR (i, 0, n - 2) {
    a.pb(b[i] | b[i + 1]);
  }
  a.pb(b.back());
  FOR (i, 0, n - 1) {
    if ((a[i] & a[i + 1]) != b[i]) {
      cout << -1 << ENDL;
      return;
    }
  }
  FOR (i, 0, n) {
    cout << a[i] << " \n"[i == n - 1];
  }
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