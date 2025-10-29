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
  int n, q;
  cin >> n >> q;
  string a, b;
  cin >> a >> b;
  vector<vi> pr_a(n + 1, vi(26, 0)), pr_b(n + 1, vi(26, 0));
  FOR (i, 0, n) {
    FOR (j, 0, 26) {
      pr_a[i + 1][j] = pr_a[i][j] + (a[i] - 'a' == j);
      pr_b[i + 1][j] = pr_b[i][j] + (b[i] - 'a' == j);
    }
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    int cnt = 0;
    FOR (j, 0, 26) {
      int c_a = pr_a[r][j] - pr_a[l - 1][j];
      int c_b = pr_b[r][j] - pr_b[l - 1][j];
      if (c_b > c_a) {
        cnt += c_b - c_a;
      }
    }
    cout << cnt << ENDL;
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