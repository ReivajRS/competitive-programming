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
    return max(x, y);
  }
  void pull(int k) {
    st[k] = merge(st[lc], st[rc]);
  }
  void apply(T val, int k, int l, int r) {
    st[k] += val;
    lazy[k] += val;
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
      return NEUT;
    }
    if (a <= l && r <= b) {
      return st[k];
    }
    int m = (l + r) >> 1;
    return merge(query(a, b, lp), query(a, b, rp));
  }
  int lower_bound(int val, int lb, int k, int l, int r) {
    push(k, l, r);
    if (l + 1 == r) {
      return l;
    }
    int m = (l + r) >> 1;
    if (st[lc] >= val && m > lb) {
      int i = lower_bound(val, lb, lp);
      if (i != -1) {
        return i;
      }
    }
    if (st[rc] >= val && r > lb) {
      return lower_bound(val, lb, rp);
    }
    return -1;
  }
  STree(int _n) : n(_n), st((n << 2) + 1, NEUT), lazy((n << 2) + 1, NEUT), has_lazy((n << 2) + 1, false) {}
  void update(int a, int b, T val) {
    update(a, b, val, 0, 0, n);
  }
  T query(int a, int b) {
    return query(a, b, 0, 0, n);
  }
  int lower_bound(int x, int l) {
    return lower_bound(x, l, 0, 0, n);
  }
};

signed main() {
  int n, m;
  cin >> n >> m;

  STree<int> st(n);

  while (m--) {
    int op;
    cin >> op;
    if (op == 1) {
      int l, r, v;
      cin >> l >> r >> v;
      st.update(l, r, v);
    }
    else {
      int x, l;
      cin >> x >> l;
      cout << st.lower_bound(x, l) << '\n';
    }
  }
}