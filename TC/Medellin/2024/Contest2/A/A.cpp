#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'

/**
 * Descripcion: arbol de segmentos, bastante poderoso para
 * realizar consultas de rango y actualizaciones de punto,
 * se puede utilizar cualquier operacion conmutativa, es decir,
 * aquella en donde el orden de evaluacion no importe: suma,
 * multiplicacion, XOR, OR, AND, MIN, MAX, etc.
 * Tiempo: O(n log n) en construccion y O(log n) por consulta
 */
#define NEUT -1e5
#define oper(a, b) max(a, b)
template <class T>
struct SegTree {
  int n;
  vector<T> A, st;

  inline int lc(int p) { return (p << 1) + 1; }
  inline int rc(int p) { return (p << 1) + 2; }

  void init(vector<T> v) {
    A = v;
    n = SZ(A);
    st.resize(n * 4);
    build(0, 0, n - 1);
  }

  void build(int p, int L, int R) {
    if (L == R) {
      st[p] = A[L];
      return;
    }
    int m = (L + R) >> 1;
    build(lc(p), L, m);
    build(rc(p), m + 1, R);
    st[p] = oper(st[lc(p)], st[rc(p)]);
  }

  T query(int l, int r, int p, int L, int R) {
    if (L > R) {
      return NEUT;
    }
    if (l <= L && r >= R) return st[p];
    if (l > R || r < L) return NEUT;
    int m = (L + R) >> 1;
    return oper(query(l, r, lc(p), L, m), query(l, r, rc(p), m + 1, R));
  }
  T query(int l, int r) { return query(l, r, 0, 0, n - 1); }

  void update(int i, T val, int p, int L, int R) {
    if (L > i || R < i) return;
    if (L == R) {
      st[p] = val;
      return;
    }
    int m = (L + R) >> 1;
    update(i, val, lc(p), L, m);
    update(i, val, rc(p), m + 1, R);
    st[p] = oper(st[lc(p)], st[rc(p)]);
  }
  void update(int i, T val) { update(i, val, 0, 0, n - 1); }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, c, m;
  cin >> n >> c >> m;
    
  // dp[i] = p[i] + max(-C * |x[i] - x[j]| + dp[j])
  // dp[i] = p[i] + C * x[i] + max(dp[j] - C * x[j]) izquierda
  // dp[i] = p[i] - C * x[i] + max(dp[j] + C * x[j]) derecha
  SegTree<ll> stl, str;
  stl.init(vector<ll>(n + 10, 0));
  str.init(vector<ll>(n + 10, 0));
  stl.update(1, -c);
  str.update(1, c);
  
  ll ans = 0;
  FOR (i, 0, m) {
    ll t, p;
    cin >> t >> p;
    ll curr = p + c * t + stl.query(1, t - 1);
    curr = max(curr, p - c * t + str.query(t + 1, n));
    stl.update(t, curr - c * t);
    str.update(t, curr + c * t);
    ans = max(ans, curr);
  }
  cout << ans << ENDL;

  return 0;
}