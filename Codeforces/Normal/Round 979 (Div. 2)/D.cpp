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
  1 4 2 5 3
  RRRLL
  1 2 4 5 3   -> R
  1 2 4 3 5   -> L
  1 2 3 4 5   -> R

  1 2 4    3 5

  RRRRL
  1 2 4 5 3   -> R
  1 2 4 3 5   -> L
  1 2 3 4 5   -> R

  RRLRL
  1 2 4 5 3   -> R
  1 2 4 3 5   -> L
  1 2 4 3 5   -> 
*/

void solve() {
  int n, q;
  cin >> n >> q;
  vi p(n);
  FOR (i, 0, n) {
    cin >> p[i];
  }
  string s;
  cin >> s;
  while (q--) {
    int x;
    cin >> x;
    s[x - 1] = (s[x - 1] == 'L' ? 'R' : 'L');

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