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
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve() {
  int n, m;
  cin >> n >> m;
  
  int a[n][m], b[n][m];
  
  FOR (i, 0, n) {
    string s;
    cin >> s;
    FOR (j, 0, m) {
      a[i][j] = s[j] - '0';
    }
  }
  
  FOR (i, 0, n) {
    string s;
    cin >> s;
    FOR (j, 0, m) {
      b[i][j] = s[j] - '0';
    }
  }

  FOR (i, 0, n) {
    int s1 = 0, s2 = 0;
    FOR (j, 0, m) {
      s1 += a[i][j];
      s2 += b[i][j];
    }
    if (s1 % 3 != s2 % 3) {
      cout << "NO" << ENDL;
      return;
    }
  }

  FOR (j, 0, m) {
    int s1 = 0, s2 = 0;
    FOR (i, 0, n) {
      s1 += a[i][j];
      s2 += b[i][j];
    }
    if (s1 % 3 != s2 % 3) {
      cout << "NO" << ENDL;
      return;
    }
  }

  cout << "YES" << ENDL;
}

signed main() { __
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}