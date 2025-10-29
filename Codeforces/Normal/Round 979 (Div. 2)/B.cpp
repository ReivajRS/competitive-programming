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

/*
  010101
  
  Solo con 0
  0
    0
      0
  0 0
  0   0
    0 0
  0 0 0
  f(t) = 7
  2 ** n - 1

  Contiene 1
  01
  010
  0101
  01010
  010101
  0 0101
  0  101
  0   01
  0    1

*/

/*
  010
  f(t) = 3
  g(t) = 4

  2**3 - 1 = 7 - 3 = 4
*/

void solve() {
  int n;
  cin >> n;
  FOR (i, 0, n - 1) {
    cout << '0';
  }
  cout << '1' << ENDL;
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