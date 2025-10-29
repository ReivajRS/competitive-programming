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

vl conv(const vl &a, const vl &b) {
  if (a.empty() || b.empty()) return {};
  vl res(SZ(a) + SZ(b) - 1);
  int L = 32 - __builtin_clz(SZ(res)), n = 1 << L;
  vector<C> in(n), out(n);
  copy(ALL(a), begin(in));
  FOR (i, 0, SZ(b))
    in[i].imag(b[i]);
  fft(in);
  for (C &x : in) x *= x;
  FOR (i, 0, n)
    out[i] = in[-i & (n - 1)] - conj(in[i]);
  fft(out);
  FOR (i, 0, SZ(res))
    res[i] = floor(imag(out[i]) / (4 * n) + 0.5);
  return res;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n,x,y;
  cin >> n >> x >> y;
  vl a(x + 1,0),b(x + 1,0);
  FOR(i,0,n+1){
    int xx;
    cin >> xx;
    a[xx] = 1;
    b[x-xx] = 1;
  }
  vl res = conv(a,b);
  vl res2(1e6+3,0);
  FOR(i,x+1,SZ(res)){
    if(res[i]){
      // cout << i << " " << abs(x-i) * 2 + y*2 << ENDL;
      if(abs(x-i) * 2 + y*2 > 1e6+5) continue;
      res2[abs(x-i) * 2 + y*2] = 1;
    }
  }
  vi ans(1e6+5,-1);
  FOR(i,1,SZ(res2)){
    if(!res2[i]) continue;
    for (int j = i; j < SZ(ans); j += i) {
      ans[j] = i;
    }
  }

  int q;
  cin >> q;
  while(q--){
    int l;
    cin >> l;
    cout << ans[l] << " ";
  }


  return 0;
}