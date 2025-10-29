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
  T merge(T x, T y) {
    return x + y;
  }
  void pull(int k) {
    st[k] = merge(st[lc], st[rc]);
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
  void update(int i, int k, int l, int r) {
    if (l + 1 == r) {
      st[k] ^= 1;
      return;
    }
    int m = (l + r) >> 1;
    if (i < m) {
      update(i, lp);
    }
    else {
      update(i, rp);
    }
    pull(k);
  }
  T query(int a, int b, int k, int l, int r) {
    if (r <= a || l >= b) {
      return NEUT;
    }
    if (a <= l && r <= b) {
      return st[k];
    }
    int m = (l + r) >> 1;
    return merge(query(a, b, lp), query(a, b, rp));
  }
  int lower_bound(T val, int k, int l, int r) {
    if (l + 1 == r) {
      return l;
    }
    int m = (l + r) >> 1;
    if (val <= st[lc]) {
      return lower_bound(val, lp);
    }
    return lower_bound(val - st[lc], rp);
  }
  STree(int _n) : n(_n), st((n << 2) + 1, NEUT) {}
  STree(vector<T> &a) : STree((int)a.size()) {
    build(a, 0, 0, n);
  }
  void update(int i) {
    update(i, 0, 0, n);
  }
  T query(int a, int b) {
    return query(a, b, 0, 0, n);
  }
  int lower_bound(int k) {
    return lower_bound(k, 0, 0, n);
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  for (auto &x : a) {
    cin >> x;
  }

  STree st(a);

  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int i;
      cin >> i;
      st.update(i);
    }
    else {
      int k;
      cin >> k;
      cout << st.lower_bound(k + 1) << '\n';
    }
  }

  return 0;
}