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
  010
  0 and 1 or 0
  0 or 1 and 0
*/

/*
  0110
  0 or 1 or 1 and 0
  0 or 1 or 0
  1 or 0
  1
*/

/*
  01100
  0 or 1 or 1 and 0
  0 or 1 or 0
*/

/*
  1100000
  1 or 1 -> no importa lo que haya a la derecha, va a dar 1 al final
*/

/*
  10101
  1 or 0 and 1 and 0 or 1
  1 or 0 and 0 or 1
  1 or 0 or 1
  1 or 1
  1
*/

/*
  101
  1 or 1 and 0
  1 or 0
  1
*/

/*
  01010
  0 or 1 and 0 or 1 and 0
  0 or 0 or 1 and 0
  0 or 0 or 0
  0

  0 or 1 and 0 and 1 or 0
  0 or 0 and 1 or 0
  0 or 0 or 0
  0
*/

/*
  1001
  1 or 0 or 0 and 1
  1 or 0 or 0
  1 or 0
  1
*/

/*
  010010
  0 or 1 and 0 or 0 and 1 or 0
  0 or 0 or 0 and 1 or 0
  0 or 0 or 0 or 0
  0
*/

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  if (s[0] == '1' || s[n - 1] == '1' || (n >= 2 && s.find("11") != -1)) {
    cout << "YES" << ENDL;
  }
  else {
    cout << "NO" << ENDL;
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