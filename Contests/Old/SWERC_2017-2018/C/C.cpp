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
#define ROF(i, a, b) for (int i = a-1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

constexpr ll MOD = 1e9;

template <typename T>
struct Matrix {
  using VVT = vector<vector<T>>;

  VVT M;
  int n, m;

  Matrix(VVT aux) : M(aux), n(M.size()), m(M[0].size()) {}

  Matrix operator*(Matrix& other) const {
    int k = other.M[0].size();
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

vector<vector<ll>> M(260, vector<ll>(260, 0));
ll n, m, m1, m2;

void f(int b) {
    if (b == n) {
        M[m1][m2]++;
        return;
    }

    m1 |= (1 << b);
    f(b + 1);
    m1 &= ~(1 << b);

    m2 |= (1 << b);
    f(b + 1);
    m2 &= ~(1 << b);

    f(b + 1);
    if (b < n - 1)
        f(b + 2);
}

signed main() {__
    cin >> n >> m;
    f(0);

    Matrix<ll> matrix = Matrix(M);
    matrix = matrix ^ m;
    cout << matrix.M[0][0] << ENDL;

    return 0;
}