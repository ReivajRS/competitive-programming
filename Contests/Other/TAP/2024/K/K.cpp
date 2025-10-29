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

  vector<string> mat(n);
  vector<vi> pr(n, vi(m + 1, 0));
  vector<vi> pc(n + 1, vi(m, 0));
  
  FOR (i, 0, n) {
    cin >> mat[i];
  }

  FOR (i, 0, n) {
    FOR (j, 0, m) {
      pr[i][j + 1] = pr[i][j] + (mat[i][j] == '#');
    }
  }
  FOR (j, 0, m) {
    FOR (i, 0, n) {
      pc[i + 1][j] = pc[i][j] + (mat[i][j] == '#');
    }
  }


  // FOR (i, 0, n) {
  //   FOR (j, 0, m + 1) {
  //     cout << pr[i][j] << ' ';
  //   }
  //   cout << ENDL;
  // }

  // cout << ENDL;

  // FOR (i, 0, n + 1) {
  //   FOR (j, 0, m) {
  //     cout << pc[i][j] << ' ';
  //   }
  //   cout << ENDL;
  // }

  vi cnt(3, 0);

  FOR (i, 0, n) {
    FOR (j, 0, m) {
      if (mat[i][j] == '#') {
        if (j + 2 < m && i + 4 < n
            && pr[i][j + 3] - pr[i][j] == 3
            && pr[i + 2][j + 3] - pr[i + 2][j] == 3
            && pc[i + 5][j] - pc[i][j] == 5
            && pc[i + 5][j + 1] - pc[i][j + 1] == 2
            && pc[i + 5][j + 2] - pc[i][j + 2] == 5
        ) {
          cnt[1]++;
          FOR (k, 0, 3) {
            mat[i][j + k] = '.';
            mat[i + 2][j + k] = '.';
          }
          FOR (k, 0, 5) {
            mat[i + k][j] = '.';
            mat[i + k][j + 2] = '.';
          }
          continue;
        }
        if (j + 2 < m && i + 4 < n
            && pr[i][j + 3] - pr[i][j] == 3
            // && pc[i + 5][j] - pc[i][j] == 1
            && pc[i + 5][j + 1] - pc[i][j + 1] == 5
            // && pc[i + 5][j + 2] - pc[i][j + 2] == 1
        ) {
          cnt[0]++;
          FOR (k, 0, 3) mat[i][j + k] = '.';
          FOR (k, 0, 5) mat[i + k][j + 1] = '.';
          continue;
        }
        if (j + 2 < m && i + 4 < n
            && pr[i][j + 3] - pr[i][j] == 3
            && pc[i + 5][j] - pc[i][j] == 5
            && pc[i + 3][j + 2] - pc[i][j + 2] == 3
            && pr[i + 2][j + 3] - pr[i + 2][j] == 3
            // && pc[i + 5][j + 1] - pc[i][j + 1] == 2
            && pc[i + 3][j + 1] - pc[i][j + 1] == 2
            // && pc[i + 5][j + 2] - pc[i][j + 2] == 3
        ) {
          cnt[2]++;;
          FOR (k, 0, 3) {
            mat[i][j + k] = '.';
            mat[i + 2][j + k] = '.';
            mat[i + k][j + 2] = '.';
          }
          FOR (k, 0, 5) {
            mat[i + k][j] = '.';
          }
        }
      }
    }
  }

  cout << cnt[0] << ' ' << cnt[1] << ' ' << cnt[2] << ENDL;

  return 0;
}