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

vector<vector<vector<vector<ll>>>> dp;
int n, o;

// last: 1 = R, 0 = O

ll solve(int i, int c, bool last, bool& fst) {
  if (i == n)
    return c == o && !(last == 0 && fst == 0);
  if (c > o)
    return 0;
  ll &ans = dp[i][c][last][fst];
  if (ans != -1)
    return ans;
  ans = 0;
  if (last)
    ans += solve(i + 1, c + 1, 0, fst);
  ans += solve(i + 1, c, 1, fst);
  return ans;
}

signed main() { __
  int tc = 0;
  while (cin >> n) {
    if (!n) break;
    tc++;

    if (n < 4 || n % 2 != 0) {
      cout << "Case " << tc << ": 0" << ENDL;
      continue;
    }

    o = (n - 4) / 2;

    dp.assign(n + 1, vector<vector<vector<ll>>>(o + 1, vector<vector<ll>>(2, vector<ll>(2, -1))));

    bool stO = 0, stR = 1;
    cout << "Case " << tc << ": " << solve(1, 1, 0, stO) + solve(1, 0, 1, stR) << ENDL;
  }
  return 0;
}