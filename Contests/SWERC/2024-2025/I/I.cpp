#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

int dp(int i, vector<vector<int>>& g, vector<int>& memo) {
  int& ret = memo[i];
  if (ret != -1) {
    return ret;
  }
  ret = 0;
  for (int j : g[i]) {
    ret = max(ret, dp(j, g, memo));
  }
  return ++ret;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<vector<int>> g(n);
  for (int i = 0; i < n; ++i) {
    int d;
    cin >> d;
    while (d--) {
      int j;
      cin >> j;
      --j;
      g[i].push_back(j);
    }
  }

  vector<int> memo(n, -1);
  for (int i = 0; i < n; ++i) {
    dp(i, g, memo);
  }
  cout << (*max_element(memo.begin(), memo.end()) == n) << '\n';

  return 0;
}