#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a-1; i >= b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

#define N_MAX 505
#define K_MAX 15

constexpr int di[3] = {-1, 0, 1}, dj[3] = {1, 1, 1};
constexpr ll INF = 1e12;

int N, M, K;
ll a[N_MAX][N_MAX];
ll dp[N_MAX][N_MAX][K_MAX];

int valid(int i, int j) {
  return i >= 0 && i < N && j >= 0 && j < M && a[i][j] != -1;
}

int is_pass(int i, int j) {
  return i > 0 && i < N - 1 && j > 0 && j < M - 1 &&
  min({a[i - 1][j], a[i + 1][j], a[i][j - 1], a[i][j + 1]}) != -1 &&
  a[i - 1][j] > a[i][j] && a[i + 1][j] > a[i][j] && a[i][j - 1] < a[i][j] && a[i][j + 1] < a[i][j];
}

ll solve(int i, int j, int k) {
  if (k > K) {
    return INF;
  }
  if (j == M - 1) {
    return (k == K ? 0 : INF);
  }
  ll &ans = dp[i][j][k];
  if (~ans) {
    return ans;
  }
  ans = INF;
  FOR (dir, 0, 3) {
    int ii = i + di[dir], jj = j + dj[dir];
    if (valid(ii, jj)) {
      ans = min(ans, a[ii][jj] + solve(ii, jj, k + is_pass(ii, jj)));
    }
  }
  return ans;
}

signed main() { __
  cin >> N >> M >> K;
  FOR (i, 0, N) {
    FOR (j, 0, M) {
      cin >> a[i][j];
    }
  }

  memset(dp, -1, sizeof dp);

  ll ans = INF;
  FOR (i, 0, N) {
    if (a[i][0] != -1) {
      ans = min(ans, a[i][0] + solve(i, 0, 0));
    }
  }
  if (ans == INF) {
    cout << "impossible" << ENDL;
    return 0;
  }
  cout << ans << ENDL;

  return 0;
}