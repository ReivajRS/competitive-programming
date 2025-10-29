#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vi> mat(n, vi(m, -1));
  FOR (i, 0, n) {
    FOR (j, 0, m) {
      char c;
      cin >> c;
      mat[i][j] = (c == 'W' ? 0 : 1);
    }
  }
  if (mat[0][0] == mat[n - 1][m - 1] || mat[n - 1][0] == mat[0][m - 1]) {
    cout << "YES" << ENDL;
    return;
  }

  int p1, p2, p3, p4;
  p1 = p2 = p3 = p4 = 0;

  FOR (i, 0, n) {
    if (mat[i][0] != mat[0][0]) {
      p1++;
      break;
    }
  }
  FOR (j, 0, m) {
    if (mat[0][j] != mat[0][0]) {
      p1++;
      break;
    }
  }

  FOR (i, 0, n) {
    if (mat[i][m - 1] != mat[0][m - 1]) {
      p2++;
      break;
    }
  }
  FOR (j, 0, m) {
    if (mat[0][j] != mat[0][m - 1]) {
      p2++;
      break;
    }
  }

  FOR (i, 0, n) {
    if (mat[i][0] != mat[n - 1][0]) {
      p3++;
      break;
    }
  }
  FOR (j, 0, m) {
    if (mat[n - 1][j] != mat[n - 1][0]) {
      p3++;
      break;
    }
  }

  FOR (i, 0, n) {
    if (mat[i][m - 1] != mat[n - 1][m - 1]) {
      p4++;
      break;
    }
  }
  FOR (j, 0, m) {
    if (mat[n - 1][j] != mat[n - 1][m - 1]) {
      p4++;
      break;
    }
  }

  if (p1 == 2 || p2 == 2 || p3 == 2 || p4 == 2)
    cout << "YES" << ENDL;
  else
    cout << "NO" << ENDL;
}

signed main() { __
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}