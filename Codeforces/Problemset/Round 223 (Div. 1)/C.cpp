#include <bits/stdc++.h>
using namespace std;

struct STree {
  #define lc (k << 1) + 1
  #define rc (k << 1) + 2
  #define lp lc, l, m
  #define rp rc, m, r
  struct Node {
    int op, cl, seq;
    Node(int _op, int _cl, int _seq) : op(_op), cl(_cl), seq(_seq) {}
  };
  const Node NEUT = Node(0, 0, 0);
  int n;
  vector<Node> st;
  Node merge(Node x, Node y) {
    int op = y.op, cl = x.cl;
    int seq = x.seq + y.seq + min(x.op, y.cl) * 2;
    if (x.op > y.cl) {
      op += x.op - y.cl;
    }
    else if (x.op < y.cl) {
      cl += y.cl - x.op;
    }
    return Node(op, cl, seq);
  }
  void pull(int k) {
    st[k] = merge(st[lc], st[rc]);
  }
  void build(vector<bool> &a, int k, int l, int r) {
    if (l + 1 == r) {
      st[k] = a[l] == 1 ? Node(1, 0, 0) : Node(0, 1, 0);
      return;
    }
    int m = (l + r) >> 1;
    build(a, lp);
    build(a, rp);
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
  STree(vector<bool> &a) : STree((int)a.size()) {
    build(a, 0, 0, n);
  }
  Node query(int a, int b) {
    return query(a, b, 0, 0, n);
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  cin >> s;

  int n = int(s.size()), m;
  cin >> m;

  vector<bool> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = s[i] == '(';
  }

  STree st(a);

  while (m--) {
    int l, r;
    cin >> l >> r;
    cout << st.query(l - 1, r).seq << '\n';
  }

  return 0;
}