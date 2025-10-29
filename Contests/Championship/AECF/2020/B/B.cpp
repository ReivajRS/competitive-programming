#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i,a,b) for(int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<vi> up_border(n + 1, vi(m + 1, 0));
  vector<vi> down_border(n + 1, vi(m + 1, n + 1));
  vector<vector<bool>> broken(n + 1, vector<bool>(m + 1, 0));

  ll cnt = 1ll * n * (n + 1) / 2 * m * (m + 1) / 2;

  FOR (i, 0, n * m) {
    int a, b;
    cin >> a >> b;

    int up_l = 0, down_l = n + 1;
    for (int l = b; l >= 1; l--) {
      if (broken[a][l]) break;
      up_l = max(up_l, up_border[a][l]);
      down_l = min(down_l, down_border[a][l]);
      int up_r = up_l, down_r = down_l;
      for (int r = b; r <= m; r++) {
        if (broken[a][r]) break;
        up_r = max(up_r, up_border[a][r]);
        down_r = min(down_r, down_border[a][r]);
        int dist_up = a - up_r;
        int dist_down = down_r - a;
        cnt -= 1ll * dist_up * dist_down;
      }
    }

    broken[a][b] = 1;
    for (int y = a - 1; y >= 1; y--) {
      if (broken[y][b]) break;
      down_border[y][b] = a;
    }
    for (int y = a + 1; y <= n; y++) {
      if (broken[y][b]) break;
      up_border[y][b] = a;
    }

    cout << cnt << ENDL;
  }

  return 0;
}