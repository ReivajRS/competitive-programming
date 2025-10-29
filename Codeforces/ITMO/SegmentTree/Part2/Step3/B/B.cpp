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
  vector<T> st;
  vector<bool> has_lazy;
  T merge(T x, T y) {
    return x + y;
  }
  void pull(int k) {
    st[k] = merge(st[lc], st[rc]);
  }
  void apply(int k, int l, int r) {
    st[k] = (r - l) - st[k];
    has_lazy[k] = !has_lazy[k];
  }
  void push(int k, int l, int r) {
    if (!has_lazy[k] || l + 1 == r) {
      return;
    }
    int m = (l + r) >> 1;
    apply(lp);
    apply(rp);
    has_lazy[k] = false;
  }
  void update(int a, int b, int k, int l, int r) {
    push(k, l, r);
    if (a >= r || b <= l) {
      return;
    } 
    if (a <= l && r <= b) {
      apply(k, l, r);
      return;
    }
    int m = (l + r) >> 1;
    update(a, b, lp);
    update(a, b, rp);
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
  int lower_bound(int val, int k, int l, int r) {
    push(k, l, r);
    if (l + 1 == r) {
      return l;
    }
    int m = (l + r) >> 1;
    if (st[lc] >= val) {
      return lower_bound(val, lp);
    }
    return lower_bound(val - st[lc], rp);
  }
  STree(int _n) : n(_n), st((n << 2) + 1, NEUT), has_lazy((n << 2) + 1, false) {}
  void update(int a, int b) {
    update(a, b, 0, 0, n);
  }
  T query(int a, int b) {
    return query(a, b, 0, 0, n);
  }
  int lower_bound(int k) {
    return lower_bound(k, 0, 0, n);
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
      int l, r;
      cin >> l >> r;
      st.update(l, r);
    }
    else {
      int k;
      cin >> k;
      cout << st.lower_bound(k + 1) << '\n';
    }
  }
}