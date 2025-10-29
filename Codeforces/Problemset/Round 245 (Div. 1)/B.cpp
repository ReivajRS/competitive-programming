#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy

constexpr int maxn = 1001;
int a[maxn][maxn];
int dp1_st[maxn][maxn], dp2_st[maxn][maxn];
int dp1_end[maxn][maxn], dp2_end[maxn][maxn];

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  dp1_st[0][0] = a[0][0];
  dp2_st[n - 1][0] = a[n - 1][0];
  dp1_end[n - 1][m - 1] = a[n - 1][m - 1];
  dp2_end[0][m - 1] = a[0][m - 1];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i - 1 >= 0) dp1_st[i][j] = max(dp1_st[i][j], dp1_st[i - 1][j] + a[i][j]);
      if (j - 1 >= 0) dp1_st[i][j] = max(dp1_st[i][j], dp1_st[i][j - 1] + a[i][j]);
    }
  }

  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < m; j++) {
      if (i + 1 < n) dp2_st[i][j] = max(dp2_st[i][j], dp2_st[i + 1][j] + a[i][j]);
      if (j - 1 >= 0) dp2_st[i][j] = max(dp2_st[i][j], dp2_st[i][j - 1] + a[i][j]);
    }
  }

  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      if (i + 1 < n) dp1_end[i][j] = max(dp1_end[i][j], dp1_end[i + 1][j] + a[i][j]);
      if (j + 1 < m) dp1_end[i][j] = max(dp1_end[i][j], dp1_end[i][j + 1] + a[i][j]);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = m - 1; j >= 0; j--) {
      if (i - 1 >= 0) dp2_end[i][j] = max(dp2_end[i][j], dp2_end[i - 1][j] + a[i][j]);
      if (j + 1 < m) dp2_end[i][j] = max(dp2_end[i][j], dp2_end[i][j + 1] + a[i][j]);
    }
  }

  int ans = 0;

  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < m - 1; j++) {
      ans = max(ans, dp1_st[i][j - 1] + dp1_end[i][j + 1] + dp2_st[i + 1][j] + dp2_end[i - 1][j]);
      ans = max(ans, dp1_st[i - 1][j] + dp1_end[i + 1][j] + dp2_st[i][j - 1] + dp2_end[i][j + 1]);
    }
  }

  cout << ans << '\n';
  
  return 0;
}