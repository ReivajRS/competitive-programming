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

template <class T>
class LazySegmentTree {
 private:
  int n;
  const T neutral = 1e9;  // Cambiar segun la operacion
  vector<T> A, lazy;
  vector<pi> st;

  inline int l(int p) { return (p << 1) + 1; }  // ir al hijo izquierdo
  inline int r(int p) { return (p << 1) + 2; }  // ir al hijo derecho

  // Cambiar segun la operacion
  T merge(pi a, pi b) {
    if (a.first == b.first) return {a.first, a.second + b.second};
    return min(a, b);
  }

  // Nota: Si se utiliza para el minimo o maximo de un rango no se le agrega el (end - start + 1)
  void propagate(int index, int start, int end, T dif) {
    st[index].first += dif;
    if (start != end) {
      lazy[l(index)] += dif;
      lazy[r(index)] += dif;
    }
    lazy[index] = 0;
  }

  void add(int index, int start, int end, int i, int j, T val) {
    if (lazy[index]) {
      propagate(index, start, end, lazy[index]);
    }

    if ((end < i) || (start > j))
      return;

    if (start >= i && end <= j) {
      propagate(index, start, end, val);
      return;
    }
    int mid = (start + end) / 2;

    add(l(index), start, mid, i, j, val);
    add(r(index), mid + 1, end, i, j, val);

    st[index] = merge(st[l(index)], st[r(index)]);
  }

  pi query(int index, int start, int end, int i, int j) {
    if (lazy[index]) {
      propagate(index, start, end, lazy[index]);
    }

    if (end < i || start > j)
      return neutral;
    if ((i <= start) && (end <= j))
      return st[index];

    int mid = (start + end) / 2;

    return merge(query(l(index), start, mid, i, j), query(r(index), mid + 1, end, i, j));
  }

  void build(int index, int start, int end, int i, int j, T val) {
    if ((end < i) || (start > j)) return;
    if (start >= i && end <= j) {
      propagate(index, start, end, val);
      return;
    }
    int mid = (start + end) / 2;
    add(l(index), start, mid, i, j, val); add(r(index), mid + 1, end, i, j, val);
    st[index] = merge(st[l(index)], st[r(index)]);
  }

 public:
  LazySegmentTree(int sz) : n(sz), st(4 * n), lazy(4 * n) {}
  void add(int i, int j, T val) { add(0, 0, n - 1, i, j, val); }  // [i, j]
  pi query(int i, int j) { return query(0, 0, n - 1, i, j); }      // [i, j]
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n,k;
  cin >> n>>k;
  vi a(n);
  FOR(i,0,n){
    cin >> a[i];
    a[i]--;
  }

  LazySegmentTree<int> st(n);

  vi last_l(n), last_r(n), ap(n);
  int ans = 0;
  FOR (i, 0, n) {
    ap[a[i]]++;
    if (ap[a[i]] == k) 
    // sumar -1 al viejo intervalo (si hay)
    // if () // sumar 1 al nuevo intervalo
    auto [mn, cnt] = st.query(0, i);
    // if (mn == 0) ans += cnt;
  }  

  cout << ans << ENDL;

  return 0;
}