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
  int n, k;
  cin >> n >> k;
  vector<string> mat(n), mat2;
  FOR (i, 0, n) {
    cin >> mat[i];
    string s = "";
    if (i % k == 0) {
      FOR (j, 0, n) {
        if (j % k == 0) {
          s += mat[i][j];
        }
      }
      mat2.pb(s);
    }
  }
  for (auto &x : mat2)
    cout << x << ENDL;
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