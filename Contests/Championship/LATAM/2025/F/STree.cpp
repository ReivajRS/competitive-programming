#include <bits/stdc++.h>
using namespace std;

struct STree {
  static const int INF = 1e9 + 5;
  struct Node {
    int l, r, min1, min2, lazy;
    Node(int l, int r)
    : l(l), r(r), min1(0), min2(INF), lazy(0) {}
  };
  int n;
  vector<Node> st;
  STree(int n) : n(n), st(1, Node(0, 0)) {}
  void merge(Node& node, Node& x, Node& y) {
    if (x.min1 < y.min1) {
      node.min1 = x.min1;
      node.min2 = min(x.min2, y.min1);
    }
    else if (y.min1 < x.min1) {
      node.min1 = y.min1;
      node.min2 = min(y.min2, x.min1);
    }
    else {
      node.min1 = x.min1;
      node.min2 = min(x.min2, y.min2);
    }
  }
  int clone(int v) {
    st.push_back(st[v]);
    return int(st.size()) - 1;
  }
  void apply(int v, int tl, int tr, int val) {
    st[v].min1 = val;
    st[v].lazy = max(st[v].lazy, val);
  }
  void push(int v, int tl, int tr) {
    if (st[v].lazy == 0 || tl + 1 == tr) {
      return;
    }
    int tm = (tl + tr) / 2;
    st[v].l = clone(st[v].l);
    st[v].r = clone(st[v].r);
    apply(st[v].l, tl, tm, st[v].lazy);
    apply(st[v].r, tm, tr, st[v].lazy);
    st[v].lazy = 0;
  }
  int query(int v, int tl, int tr, int l, int r, int carry = 0) {
    if (tr <= l || r <= tl) {
      return INF;
    }
    carry = max(carry, st[v].lazy);
    if (l <= tl && tr <= r) {
      return max(st[v].min1, carry);
    }
    int tm = (tl + tr) / 2;
    return min(query(st[v].l, tl, tm, l, r, carry), query(st[v].r, tm, tr, l, r, carry));
  }
  int update(int v, int tl, int tr, int l, int r, int val) {
    if (tr <= l || r <= tl || val <= st[v].min1) {
      return v;
    }
    v = clone(v);
    if (l <= tl && tr <= r && val < st[v].min2) {
      apply(v, tl, tr, val);
      return v;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    st[v].l = update(st[v].l, tl, tm, l, r, val);
    st[v].r = update(st[v].r, tm, tr, l, r, val);
    merge(st[v], st[st[v].l], st[st[v].r]);
    return v;
  }
  int query(int root, int l, int r) {
    return query(root, 0, n, l, r);
  }
  int update(int root, int l, int r, int val) {
    return update(root, 0, n, l, r, val);
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  STree st(10);
  vector<int> roots = {0};

  // cout << st.query(roots[0], 0, 1) << '\n';
  // roots.push_back(st.update(roots[0], 0, 1, 5));
  // cout << st.query(roots[1], 0, 1) << '\n';

  // roots.push_back(st.update(roots.back(), 1, 4, 3));
  // cout << st.query(roots[1], 0, 5) << '\n';
  // cout << st.query(roots[1], 1, 4) << '\n';
  // cout << st.query(roots[1], 2, 3) << '\n';

  auto print = [&](int root) -> void {
    for (int i = 0; i < 10; i++) {
      cout << st.query(root, i, i + 1) << ' ';
    }
    cout << '\n';
  };

  // roots.push_back(st.update(roots.back(), 0, 3, 2));
  // roots.push_back(st.update(roots.back(), 1, 4, 1));
  // roots.push_back(st.update(roots.back(), 2, 5, 5));
  // cout << st.query(roots[1], 0, 3) << '\n';
  // cout << st.query(roots[2], 1, 4) << '\n';
  // cout << st.query(roots[3], 3, 5) << '\n';
  // print(roots[0]);
  // print(roots[1]);
  // print(roots[2]);
  // print(roots[3]);

  // roots.push_back(st.update(roots.back(), 0, 6, 4));
  // roots.push_back(st.update(roots.back(), 2, 5, 2));
  // roots.push_back(st.update(roots.back(), 1, 4, 6));
  // cout << st.query(roots[1], 0, 6) << '\n';
  // cout << st.query(roots[3], 1, 5) << '\n';

  // roots.push_back(st.update(roots.back(), 0, 8, 3));
  // roots.push_back(st.update(roots.back(), 0, 8, 5));
  // roots.push_back(st.update(roots.back(), 2, 6, 4));

  // cout << st.query(roots[0], 0, 5) << '\n';
  // cout << st.query(roots[1], 0, 5) << '\n';
  // cout << st.query(roots[2], 0, 5) << '\n';
  // cout << st.query(roots[3], 0, 5) << '\n';

  roots.push_back(st.update(roots.back(), 0, 2 * 2 - 1, 1));
  print(roots.back());
  roots.push_back(st.update(roots.back(), 1 * 2, 4 * 2 - 1, 2));
  print(roots.back());

  cout << st.query(roots[2], 0, 2 * 2 - 1) << '\n';
  cout << st.query(roots[2], 0, 4 * 2 - 1) << '\n';


  return 0;
}