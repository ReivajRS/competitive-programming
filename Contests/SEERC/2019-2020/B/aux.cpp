ll solve(int i, int ca, int cb) {
  if (i == n) return ca == s1 && cb == s2 ? 0 : INF;
  ll &ans = dp[i][ca][cb];
  if (~ans) return ans;
  ans = solve(i + 1, ca, cb);
  if (ca != s1) {
    int nca = ca + x[i], ncb = cb;
    if (nca > s1) ncb = min(s2, ncb + nca - s1);
    ans = min(ans, t[i] + solve(i + 1, nca, ncb));
  }
  ans = min(ans, r[i] + solve(i + 1, ca, min(s2, cb + y[i])));
  return ans;
}