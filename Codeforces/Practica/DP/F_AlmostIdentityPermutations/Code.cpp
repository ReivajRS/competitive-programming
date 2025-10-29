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

signed main() { __
  int n, k;
  cin >> n >> k;

  ll comb[1001][5] = {0};

  FOR (i, 0, 1001) {
    FOR (j, 0, 5) {
      if (i == j || j == 0)
        comb[i][j] = 1;
      else
        comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
    }
  }

  int d[5] = {0};

  FOR (j, 1, 5) {
    int perm[] = {1, 2, 3, 4};
    do {
      int cnt = 0;
      FOR (i, 0, j) {
        if (i + 1 != perm[i])
          cnt++;
      }
      d[j] += (cnt == j);
    } while (next_permutation(perm, perm + j));
  }

  ll ans = 1;
  FOR (i, 1, 5) {
    if (i <= k)
      ans += comb[n][i] * d[i];
  }

  cout << ans << ENDL;

  return 0;
}