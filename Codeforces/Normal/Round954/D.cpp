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
  int n;
  cin >> n;
  
  string s;
  cin >> s;
  
  if (n == 2) {
    cout << stoll(s) << ENDL;
    return;
  }

  vector<vector<ll>> mat(n, vector<ll>(2));
  FOR (i, 0, n) {
    mat[i][0] = s[i] - '0';
    if (i + 1 <= n)
      mat[i][1] = stoll(s.substr(i, 2));
  }

  ll dp[21][21];
  memset(dp, -1, sizeof dp);
  const ll INF = 1e9;

  auto f = [&](auto &f, int i, int c) -> ll {
    if (c == 0){
      return mat[0][i];
    }
    ll &ans = dp[i][c];
    if (ans != -1)
      return ans;
    ans = INF;
    FOR (j, 0, 2) {
      if (i - j - 1 < 0)
        continue;
      ll val = mat[i - j][j];
      ans = min({ans, val + f(f, i - j - 1, c - 1), val * f(f, i - j - 1, c - 1)});
    }
    return ans;
  };

  cout << f(f, n - 1, n - 2) << ENDL;
}

signed main() { __
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}