#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, x;
  cin >> n >> x;

  if (x >= n) {
    cout << -1 << ENDL;
    return 0;
  }

  vector<vi> a(n, vi(x)), b(n);
  FOR (i, 0, n) {
    FOR (j, 0, x) {
      int y = i * x + j + 1;
      a[i][j] = y;
      b[(i + j + 1) % n].pb(y);
    }
  }

  FOR (i, 0, n) {
    FOR (j, 0, x) {
      cout << a[i][j] << " ";
    }
    FOR (j, 0, x) {
      cout << b[i][j] << " \n"[j == x - 1];
    }
  }

  return 0;
}