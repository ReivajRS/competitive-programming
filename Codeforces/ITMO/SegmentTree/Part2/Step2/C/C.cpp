#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct STree {
  #define lc (k << 1) + 1
  #define rc (k << 1) + 2
  #define lp lc, l, m
  #define rp rc, m, r
  const T NEUT = 0;
  int n;
  vector<T> st, lazy;
  vector<bool> has_lazy;
  T merge(T x, T y) {
    return x & y;
  }
  void pull(int k) {
    st[k] = merge(st[lc], st[rc]);
  }
  void apply(T val, int k, int l, int r) {
    st[k] |= val;
    lazy[k] |= val;
    has_lazy[k] = true;
  }
  void push(int k, int l, int r) {
    if (!has_lazy[k] || l + 1 == r) {
      return;
    }
    int m = (l + r) >> 1;
    apply(lazy[k], lp);
    apply(lazy[k], rp);
    lazy[k] = NEUT;
    has_lazy[k] = false;
  }
  void build(vector<T> &a, int k, int l, int r) {
    if (l + 1 == r) {
      st[k] = a[l];
      return;
    }
    int m = (l + r) >> 1;
    build(a, lp);
    build(a, rp);
    pull(k);
  }
  void update(int a, int b, T val, int k, int l, int r) {
    push(k, l, r);
    if (a >= r || b <= l) {
      return;
    } 
    if (a <= l && r <= b) {
      apply(val, k, l, r);
      return;
    }
    int m = (l + r) >> 1;
    update(a, b, val, lp);
    update(a, b, val, rp);
    pull(k);
  }
  T query(int a, int b, int k, int l, int r) {
    push(k, l, r);
    if (a >= r || b <= l) {
      return INT_MAX;
    }
    if (a <= l && r <= b) {
      return st[k];
    }
    int m = (l + r) >> 1;
    return merge(query(a, b, lp), query(a, b, rp));
  }
  STree(int _n) : n(_n), st((n << 2) + 1, NEUT), lazy((n << 2) + 1, NEUT), has_lazy((n << 2) + 1, false) {}
  STree(vector<T> &a) : STree((int)a.size()) {
    build(a, 0, 0, n);
  }
  void update(int a, int b, T val) {
    update(a, b, val, 0, 0, n);
  }
  T query(int a, int b) {
    return query(a, b, 0, 0, n);
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  STree<int> st(n);
  
  while (m--) {
    int op, l, r;
    cin >> op >> l >> r;
    if (op == 1) {
      int v;
      cin >> v;
      st.update(l, r, v);
    }
    else {
      cout << st.query(l, r) << '\n';
    }
  }

  return 0;
}