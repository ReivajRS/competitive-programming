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

const int INF = 2e9 + 5;
int n, k, p;
int a[1001], b[2001];
int dp[2001][1001];

int solve(int i, int last) {
  if (last == n)
    return 0;
  if (i == k)
    return INF;
  int &ans = dp[i][last];
  if (ans != -1)
    return ans;
  ans = INF;
  int take_this = abs(b[i] - a[last]) + abs(b[i] - p);
  ans = min(solve(i + 1, last), max(solve(i + 1, last + 1), take_this));
  return ans;
}

signed main() { __
  cin >> n >> k >> p;

  FOR (i, 0, n) {
    cin >> a[i];
  }
  FOR (i, 0, k) {
    cin >> b[i];
  }

  sort(a, a + n);
  sort(b, b + k);

  memset(dp, -1, sizeof dp);

  cout << solve(0, 0) << ENDL;

  return 0;
}