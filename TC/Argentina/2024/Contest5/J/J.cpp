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

constexpr int maxn = 1e6 + 5;

string s;
ll memo[maxn + 5][5 + 5];

ll dp(int i, int j) {
  if (j == 3) return 1;
  if (i == SZ(s) - 2) return 0;
  ll &ans = memo[i][j];
  if (~ans) return ans;
  ans = 0;
  if (j) ans += dp(i + 1, j);
  if ((j == 0 || j == 2) && s[i] == s[i + 1] && s[i] == 'v') ans += dp(i + 1, j + 1);  
  if (j == 1 && s[i] == 'o') ans += dp(i + 1, j + 1);
  return ans;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> s;

  s += "###";

  memset(memo, -1, sizeof memo);

  ll ans = 0;
  FOR (i, 0, SZ(s)) ans += dp(i, 0);
  cout << ans << ENDL;

  return 0;
}