#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct STree {
  #define lc (k << 1) + 1
  #define rc (k << 1) + 2
  #define lp lc, l, m
  #define rp rc, m, r

  struct Node {
    ll sum, pref, suff, seg;
    Node(ll _sum, ll _pref, ll _suff, ll _seg) {
      sum = _sum, pref = _pref, suff = _suff, seg = _seg;
    }
    Node(ll val) : Node(val, val, val, val) {}
  };
  const Node NEUT = Node(0, 0, 0, 0);
  Node merge(Node x, Node y) {
    ll sum = x.sum + y.sum;
    ll pref = max(x.pref, x.sum + y.pref);
    ll suff = max(y.suff, y.sum + x.suff);
    ll seg = max({x.seg, y.seg, x.suff + y.pref});
    return Node(sum, pref, suff, seg);
  }
  void pull(int k) {
    st[k] = merge(st[lc], st[rc]);
  }

  int n;
  vector<Node> st;
  void build(vector<ll> &a, int k, int l, int r) {
    if (l + 1 == r) {
      st[k] = Node(a[l]);
      return;
    }
    int m = (l + r) >> 1;
    build(a, lp);
    build(a, rp);
    pull(k);
  }
  void update(int i, ll val, int k, int l, int r) {
    if (l + 1 == r) {
      st[k] = Node(val);
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
    if (a <= l && r <= b) {
      return st[k];
    }
    int m = (l + r) >> 1;
    if (b < m) {
      return query(a, b, lp);
    }
    if (a >= m) {
      return query(a, b, rp);
    }
    return merge(query(a, b, lp), query(a, b, rp));
  }
  STree(int _n) : n(_n), st((n << 2) + 1, NEUT) {}
  STree(vector<ll> &a) : STree((int)a.size()) {
    build(a, 0, 0, n);
  }
  void update(int i, ll val) {
    update(i, val, 0, 0, n);
  }
  Node query(int a, int b) {
    return query(a, b, 0, 0, n);
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;

  vector<ll> a(n);
  for (auto &x : a) {
    cin >> x;
  }

  STree st(a);

  cout << max(0ll, st.query(0, n).seg) << '\n';

  while (q--) {
    int i;
    ll v;
    cin >> i >> v;
    st.update(i, v);
    cout << max(0ll, st.query(0, n).seg) << '\n';
  }

  return 0;
}