#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'

/*
p(x) = a_0*x0 + a1*x_1 + ...
1 2 3
p(x) = 0 + 1x + 1x² + 1x³ + 0x⁴
q(x) = 0 + 1x + 1x² + 1x³ + 0x⁴ + 0x⁵
k(x) = 0 + 0x + 1x² + 1x³ + 1x⁴ + 1x⁵ + 1x⁶
*/

using ld = double;
const ld PI = acos(-1.0);
const ld one = 1;

using C = complex<ld>;
using vd = vector<ld>;

void fft(vector<C> &a) {
  int n = SZ(a), L = 31 - __builtin_clz(n);
  static vector<complex<ld>> R(2, 1);
  static vector<C> rt(2, 1);
  for (static int k = 2; k < n; k *= 2) {
    R.resize(n);
    rt.resize(n);
    auto x = polar(one, PI / k);
    FOR (i, k, 2 * k) {
      rt[i] = R[i] = i & 1 ? R[i / 2] * x : R[i / 2];
    }
  }
  vi rev(n);
  FOR (i, 0, n) {
    rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
  }
  FOR (i, 0, n) {
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  }
  for (int k = 1; k < n; k *= 2)
    for (int i = 0; i < n; i += 2 * k) FOR (j, 0, k) {
      auto x = (ld *)&rt[j + k], y = (ld *)&a[i + j + k];
      C z(x[0] * y[0] - x[1] * y[1], x[0] * y[1] + x[1] * y[0]);
      a[i + j + k] = a[i + j] - z;
      a[i + j] += z;
    }
}

using vl = vector<ll>;

vl convMod(const vl &a, const vl &b, const int &M) {
  if (a.empty() || b.empty()) return {};
  vl res(SZ(a) + SZ(b) - 1);
  int B = 32 - __builtin_clz(SZ(res)), n = 1 << B, cut = int(sqrt(M));
  vector<C> L(n), R(n), outs(n), outl(n);
  FOR(i, 0, SZ(a))
  L[i] = C((int)a[i] / cut, (int)a[i] % cut);
  FOR(i, 0, SZ(b))
  R[i] = C((int)b[i] / cut, (int)b[i] % cut);
  fft(L), fft(R);
  FOR(i, 0, n) {
    int j = -i & (n - 1);
    outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
    outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / 1i;
  }
  fft(outl), fft(outs);
  FOR(i, 0, SZ(res)) {
    ll av = ll(real(outl[i]) + .5), cv = ll(imag(outs[i]) + .5);
    ll bv = ll(imag(outl[i]) + .5) + ll(real(outs[i]) + .5);
    res[i] = ((av % M * cut + bv) % M * cut + cv) % M;
  }
  return res;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n, k;
  cin >> k >> n;

  vl a(10);
  FOR (i, 0, n) {
    int x;
    cin >> x;
    a[x] = 1;
  }
  int MOD = 998244353;
  vl b(1, 1);
  k >>= 1;
  while (k) {
    if (k & 1) b = convMod(b, a, MOD);
    a = convMod(a, a, MOD);
    k >>= 1;
  }
  ll ans = 0;
  FOR (i, 0, SZ(b)) {
    ans += b[i] * b[i] % MOD;
    ans %= MOD;
  }
  cout << ans << ENDL;

  return 0;
}