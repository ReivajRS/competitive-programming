#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ENDL '\n'

using i64 = long long;

constexpr int MOD = 1e9 + 7;

using VVT = vector<vector<i64>>;

struct Matrix {

  int n;
  VVT M;

  Matrix(VVT aux) : n(SZ(aux)), M(aux) {}

  Matrix operator*(Matrix& other) const {
    assert(SZ(M[0]) == SZ(other.M));
    int k = SZ(other.M[0]);
    VVT C(n, vector<i64>(k, 0));
    FOR (i, 0, SZ(M)) FOR (j, 0, k) FOR (l, 0, SZ(M[0])) {
      C[i][j] = (C[i][j] + M[i][l] * other.M[l][j] % MOD) % MOD;
    }
    return Matrix(C);
  }

  Matrix operator^(i64 p) const {
    assert(p >= 0);
    Matrix ret(VVT(n, vector<i64>(n))), B(*this);
    FOR (i, 0, n) {
      ret.M[i][i] = 1;
    }
    while (p) {
      if (p & 1) {
        ret = ret * B;
      }
      p >>= 1;
      B = B * B;
    }
    return ret;
  }

  void print() {
    cout << "-----------------\n";
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cout << M[i][j] << " \n"[j == n - 1];
      }
    }
  }
};

i64 be(i64 a, int b) {
  i64 ret = 1;
  while (b) {
    if (b & 1) {
      ret = ret * a % MOD;
    }
    a = a * a % MOD;
    b >>= 1;
  }
  return ret;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);


  int n, q;
  cin >> n >> q;

  vector<string> w(n);
  for (auto& s : w) {
    cin >> s;
  }

  VVT m(105, vector<i64>(105));
  for (int i = 1; i < 105; ++i) {
    m[i][i - 1] = 1;
  }

  for (auto& mala : w) {
    ++m[0][(int)mala.size() + 1];
  }

  /*
    1zxxx      dp(i)        dp(i + 1)
    10000      dp(i - 1)    dp(i)
    01000      dp(i - 2)    dp(i - 1)
    00100      dp(i - 3)    dp(i - 2)

    1zxxx      dp(0)     dp(n)
    10000      dp(-1)    dp(i)
    01000      dp(-2)    dp(i - 1)
    00100      dp(-3)    dp(i - 2)

    M         V

    V_n = V_0 * M^n
  */

  // { dp(i), dp(i - 1), ..., }
  // { dp(i + 1), dp(i), ..., }
  // dp(i) = 23 * dp(i - 1) + sum(dp(i - |mala|))
  // dp(n) - pow(23, n)

  Matrix mtx(m);
  mtx = mtx ^ n;

  //676

  // dp[0] = 1
  // dp[1] = 26
  // dp[2] = 26 * 26
  // 26 - 

  i64 tot = be(26, n);
  cout << tot << '\n';

  i64 ans = (tot - mtx.M[0][0] + MOD) % MOD;

  cout << ans << '\n';

  return 0;
}