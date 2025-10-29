#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
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
  int a, b, c;
  cin >> a >> b >> c;

  int mx = 0;
  FOR (i, 0, 6) {
    FOR (j, 0, 6) {
      FOR (k, 0, 6) {
        if (i + j + k == 5) {
          mx = max(mx, (a + i) * (b + j) * (c + k));
        }
      }
    }
  }

  cout << mx << ENDL;
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