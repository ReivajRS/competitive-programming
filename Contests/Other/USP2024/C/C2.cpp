#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 1e9;

struct STree {
  #define ls 2 * v + 1
  #define rs 2 * v + 2
  #define lp ls, tl, tm
  #define rp rs, tm, tr
  #define NEUT 0

  struct Node {
    ll b, c;
    int stop;
    Node() : b(0), c(0), stop(INF) {}
    Node(ll b, ll c, int stop) : b(b), c(c), stop(stop) {}
  };

  Node merge(Node& l, Node& r) {
    ll sb = l.b + r.b;
    ll sc = l.c + r.c;
    int stop = INF;
    if (sb >= sc) {
      if (l.stop != INF) {
        stop = r.stop;
      }
    }
    else {
      stop = min(l.stop, r.stop);
    }
    return Node(sb, sc, stop);
  }
  
  int n;
  vector<Node> st;

  STree(int n) : n(n), st(4 * n) {}

  void update(int v, int tl, int tr, int i, int b, int c) {
    if (tl + 1 == tr) {
      int stop = b < c ? i : INF;
      st[v] = Node(b, c, stop);
      return;
    }
    int tm = (tl + tr) / 2;
    if (i < tm) {
      update(lp, i, b, c);
    }
    else {
      update(rp, i, b, c);
    }
    st[v] = merge(st[ls], st[rs]);
  }

  int query(int v, int tl, int tr, int i) {
    if (tl + 1 == tr) {
      return st[v].stop;
    }
    int tm = (tl + tr) / 2;
    int stop = tl <= i ? st[v].stop : INF;
    if (i < tm) {
      return min(stop, query(lp, i));
    }
    else {
      return min(stop, query(rp, i));
    }
  }

  void update(int i, int b, int c) {
    update(0, 0, n, i, b, c);
  }

  int query(int i) {
    return query(0, 0, n, i);
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;
  
  vector<int> b(n), c(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }

  STree st(2 * n);
  for (int i = 0; i < 2 * n; i++) {
    st.update(i, b[i % n], c[i % n]);
  }

  while (q--) {
    int op, i;
    cin >> op >> i;
    i--;
    if (op == 1) {
      int stop = st.query(i);
      if (stop >= i + n) {
        cout << -1 << '\n';
      }
      else {
        cout << stop % n + 1 << '\n';
      }
      continue;
    }
    int x;
    cin >> x;
    if (op == 2) {
      b[i] = x;
    }
    else {
      c[i] = x;
    }
    st.update(i, b[i], c[i]);
    st.update(i + n, b[i], c[i]);
  }

  return 0;
}