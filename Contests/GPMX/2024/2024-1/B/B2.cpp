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

const int MOD = 1e9 + 7;

template <typename T>
struct Matrix {
  using VVT = vector<vector<T>>;

  VVT M;
  int n, m;

  Matrix(VVT aux) : M(aux), n(SZ(M)), m(SZ(M[0])) {}

  Matrix operator*(Matrix& other) const {
    int k = SZ(other.M[0]);
    VVT C(n, vector<T>(k, 0));
    FOR(i, 0, n)
    FOR(j, 0, k)
    FOR(l, 0, m)
    C[i][j] = (C[i][j] + M[i][l] * other.M[l][j] % MOD) % MOD;
    return Matrix(C);
  }

  Matrix operator^(ll p) const {
    assert(p >= 0);
    Matrix ret(VVT(n, vector<T>(n))), B(*this);
    FOR(i, 0, n)
    ret.M[i][i] = 1;

    while (p) {
      if (p & 1)
        ret = ret * B;
      p >>= 1;
      B = B * B;
    }
    return ret;
  }
};

signed main() { __
  vector<vector<ll>> mat(20, vector<ll>(20, 0));
  
  FOR (i, 0, 19) {
    mat[i][i + 1] = 1;
  }
  
  mat[5][0] = 3;
  mat[9][0] = 3;
  mat[13][0] = 3;
  mat[17][0] = 3;

  Matrix<ll> mm(mat);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    Matrix<ll> mm2 = (mm^n);

    ll ans = 0;

    FOR (i, 0, 20) {
      ans = ans % MOD + mm2.M[0][i] % MOD;
      ans %= MOD;
    }

    cout << ans << ENDL;
  }

  return 0;
}