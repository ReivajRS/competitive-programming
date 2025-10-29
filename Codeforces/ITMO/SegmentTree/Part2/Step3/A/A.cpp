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
  Node merge(Node x, Node y) {
    ll sum = x.sum + y.sum;
    ll pref = max(x.pref, x.sum + y.pref);
    ll suff = max(y.suff, x.suff + y.sum);
    ll seg = max({x.seg, y.seg, x.suff + y.pref});
    return Node(sum, pref, suff, seg);
  }
  const Node NEUT = Node(0);

  int n;
  vector<Node> st;
  vector<ll> lazy;
  vector<bool> has_lazy;
  void pull(int k) {
    st[k] = merge(st[lc], st[rc]);
  }
  void apply(ll val, int k, int l, int r) {
    st[k] = Node(val * (r - l));
    lazy[k] = val;
    has_lazy[k] = true;
  }
  void push(int k, int l, int r) {
    if (!has_lazy[k] || l + 1 == r) {
      return;
    }
    int m = (l + r) >> 1;
    apply(lazy[k], lp);
    apply(lazy[k], rp);
    lazy[k] = 0;
    has_lazy[k] = false;
  }
  void update(int a, int b, ll val, int k, int l, int r) {
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
  Node query(int a, int b, int k, int l, int r) {
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
  STree(int _n) : n(_n), st((n << 2) + 1, NEUT), lazy((n << 2) + 1, 0), has_lazy((n << 2) + 1, false) {}
  void update(int a, int b, ll val) {
    update(a, b, val, 0, 0, n);
  }
  Node query(int a, int b) {
    return query(a, b, 0, 0, n);
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  STree st(n);

  while (m--) {
    int l, r, v;
    cin >> l >> r >> v;
    st.update(l, r, v);
    cout << max(0ll, st.st[0].seg) << '\n';
  }

  return 0;
}