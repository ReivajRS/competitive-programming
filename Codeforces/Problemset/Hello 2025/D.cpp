#include <bits/stdc++.h>
using namespace std;

struct STree {
  #define lc (k << 1) + 1
  #define rc (k << 1) + 2
  #define lp lc, l, m
  #define rp rc, m, r
  struct Node {
    int mx_l, mn_l, mx_r, mn_r, ans;
    Node(int _mx_l, int _mn_l, int _mx_r, int _mn_r, int _ans)
    : mx_l(_mx_l), mn_l(_mn_l), mx_r(_mx_r), mn_r(_mn_r), ans(_ans) {}
  };
  const int MAX = 1e9 + 2e5 + 5;
  const Node NEUT = Node(-MAX, MAX, -MAX, MAX, 0);
  int n;
  vector<Node> st;
  Node merge(Node x, Node y) {
    return Node(
      max(x.mx_l, y.mx_l),
      min(x.mn_l, y.mn_l),
      max(x.mx_r, y.mx_r),
      min(x.mn_r, y.mn_r),
      max({0, x.mx_l - y.mn_r, y.mx_r - x.mn_l, x.ans, y.ans})
    );
  }
  void pull(int k) {
    st[k] = merge(st[lc], st[rc]);
  }
  void build(vector<int> &a, int k, int l, int r) {
    if (l + 1 == r) {
      st[k] = Node(a[l] + l, a[l] - l, a[l] - l, a[l] + l, 0);
      return;
    }
    int m = (l + r) >> 1;
    build(a, lp);
    build(a, rp);
    pull(k);
  }
  void update(int i, int val, int k, int l, int r) {
    if (l + 1 == r) {
      st[k] = Node(val + l, val - l, val - l, val + l, 0);
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
  Node query(int a, int b, int k, int l, int r) {
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
  STree(vector<int> &a) : STree((int)a.size()) {
    build(a, 0, 0, n);
  }
  void update(int i, int val) {
    update(i, val, 0, 0, n);
  }
  Node query(int a, int b) {
    return query(a, b, 0, 0, n);
  }
};

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  STree st(a);
  while (q--) {
    cout << st.st[0].ans << '\n';
    int p, x;
    cin >> p >> x;
    p--;
    st.update(p, x);
  }
  cout << st.st[0].ans << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }

  return 0;
}