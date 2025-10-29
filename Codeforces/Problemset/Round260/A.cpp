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

int a[100001];
ll dp[100001];

ll solve(int i) {
  if (i <= 0)
    return 0;
  if (dp[i] != -1)
    return dp[i];
  return dp[i] = max(solve(i - 1), solve(i - 2) + 1ll * a[i] * i);
}

signed main() { __
  int n;
  cin >> n;

  FOR (i, 0, n) {
    int x;
    cin >> x;
    a[x]++;
  }

  memset(dp, -1, sizeof dp);

  cout << solve(100000) << ENDL;

  return 0;
}