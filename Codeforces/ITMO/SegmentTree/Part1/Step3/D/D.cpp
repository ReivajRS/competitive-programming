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
  void update(int i, T val, int k, int l, int r) {
    if (l + 1 == r) {
      st[k] = val;
      return;
    }
    int m = (l + r) >> 1;
    if (i < m) {
      update(i, val, lp);
    }
    else {
      update(i, val, rp);
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
  STree(int _n) : n(_n), st((n << 2) + 1, NEUT) {}
  STree(vector<T> &a) : STree((int)a.size()) {
    build(a, 0, 0, n);
  }
  void update(int i, T val) {
    update(i, val, 0, 0, n);
  }
  T query(int a, int b) {
    return query(a, b, 0, 0, n);
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<int> a(2 * n);
  for (int i = 0; i < 2 * n; i++) {
    cin >> a[i];
  }

  vector<int> ans(n + 1);
  
  auto calc = [&]() -> void {
    STree<int> st(2 * n + 1);
    vector<int> c(n + 1, -1);
    for (int i = 0; i < 2 * n; i++) {
      if (c[a[i]] == -1) {
        c[a[i]] = i;
        st.update(i, 1);
      }
      else {
        st.update(c[a[i]], 0);
        ans[a[i]] += st.query(c[a[i]], i);
      }
    }
  };

  calc();
  reverse(a.begin(), a.end());
  calc();

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';

  return 0;
}