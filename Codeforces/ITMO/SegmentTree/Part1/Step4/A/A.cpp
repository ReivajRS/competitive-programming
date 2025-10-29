#include <bits/stdc++.h>
using namespace std;

struct STree {
  #define lc (k << 1) + 1
  #define rc (k << 1) + 2
  #define lp lc, l, m
  #define rp rc, m, r
  struct Node {
    int sum[2];
    Node() {
      sum[0] = sum[1] = 0;
    }
    Node(int idx, int val) : Node() {
      sum[idx & 1] = val;
    }
  };
  const Node NEUT = Node();
  int n;
  vector<Node> st;
  Node merge(Node x, Node y) {
    Node node;
    node.sum[0] = x.sum[0] + y.sum[0];
    node.sum[1] = x.sum[1] + y.sum[1];
    return node;
  }
  void pull(int k) {
    st[k] = merge(st[lc], st[rc]);
  }
  void build(vector<int> &a, int k, int l, int r) {
    if (l + 1 == r) {
      st[k] = Node(l, a[l]);
      return;
    }
    int m = (l + r) >> 1;
    build(a, lp);
    build(a, rp);
    pull(k);
  }
  void update(int i, int val, int k, int l, int r) {
    if (l + 1 == r) {
      st[k] = Node(l, val);
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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  STree st(a);

  int q;
  cin >> q;

  while (q--) {
    int op;
    cin >> op;
    if (op == 0) {
      int i, j;
      cin >> i >> j;
      st.update(i - 1, j);
    }
    else {
      int l, r;
      cin >> l >> r;
      l--;
      STree::Node node = st.query(l, r);
      int ans = node.sum[l & 1] - node.sum[!(l & 1)];
      cout << ans << '\n';
    }
  }

  return 0;
}