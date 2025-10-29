#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

template<int MOD> struct mi {
  int v;
  mi() : v(0) {}
  mi(ll _v) : v(int(_v % MOD)) {
    v += (v < 0) * MOD;
  }
  mi& operator+=(mi o) {
    if ((v += o.v) >= MOD) v -= MOD;
    return *this;
  }
  mi& operator-=(mi o) {
    if ((v -= o.v) < 0) v += MOD;
    return *this;
  }
  friend mi operator+(mi a, mi b) {
    return a += b;
  }
  friend mi operator-(mi a, mi b) {
    return a -= b;
  }
};
using modint = mi<998244353>;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<int> l(n), r(n);
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i];
  }

  vector<modint> f(m + 1);
  for (int i = m; i; --i) {
    int N = m / i + 1;
    vector<modint> psH(N, 1);
    for (int p = 0; p < n; ++p) {
      vector<modint> newPsH(N);
      for (int k = 1; k < N; ++k) {
        newPsH[k] = newPsH[k - 1];
        int hi = k - (l[p] + i - 1) / i, lo = max(0, k - r[p] / i);
        if (lo <= hi) {
          newPsH[k] += psH[hi];
          if (lo) {
            newPsH[k] -= psH[lo - 1];
          }
        }
      }
      psH.swap(newPsH);
    }
    f[i] = psH.back();
    for (int k = 2; i*k <= m; ++k) {
      f[i] -= f[i*k];
    }
  }
  cout << f[1].v << '\n';

  return 0;
}