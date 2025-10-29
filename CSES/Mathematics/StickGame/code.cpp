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

signed main() { __
  int n, k;
  cin >> n >> k;
  vi a(k);
  for (auto &x : a)
    cin >> x;
  vector<bool> dp(n + 1);
  dp[0] = 0;
  for (auto &x : a)
    dp[x] = 1;
  FOR (i, 0, n + 1) {
    if (dp[i])
      continue;
    for (auto &x : a)
      if (i + x <= n)
        dp[i + x] = 1;
  }
  FOR (i, 1, n + 1)
    cout << (dp[i] ? 'W' : 'L');
  cout << ENDL;
  return 0;
}