#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

struct STree {
  #define ls 2 * v + 1
  #define rs 2 * v + 2
  #define lp ls, tl, tm
  #define rp rs, tm, tr

  struct Node {
    int zeros, ones, ans, rans;
    Node(int zeros, int ones, int ans, int rans) 
    : zeros(zeros), ones(ones), ans(ans), rans(rans) {}
    void invert() {
      swap(zeros, ones);
      swap(ans, rans);
    }
  };

  Node merge(Node l, Node r) {
    int zeros = l.zeros + r.zeros;
    int ones = l.ones + r.ones;
    int ans = max(l.ans + r.ones, l.zeros + r.ans);
    int rans = max(l.rans + r.zeros, l.ones + r.rans);
    return Node(zeros, ones, ans, rans);
  }

  int n;
  vector<Node> st;
  vector<bool> lazy;

  const Node NEUT = Node(0, 0, 0, 0);

  STree(int n, vector<bool>& a) : n(n), st(4 * n, NEUT), lazy(4 * n) {
    build(0, 0, n, a);
  }

  void build(int v, int tl, int tr, vector<bool>& a) {
    if (tl + 1 == tr) {
      if (a[tl]) {
        st[v] = Node(0, 1, 1, 1);
      }
      else {
        st[v] = Node(1, 0, 1, 1);
      }
      return;
    }
    int tm = (tl + tr) / 2;
    build(lp, a);
    build(rp, a);
    st[v] = merge(st[ls], st[rs]);
  }

  void apply(int v) {
    st[v].invert();
    lazy[v] = !lazy[v];
  }

  void push(int v, int tl, int tr) {
    if (lazy[v]) {
      apply(ls);
      apply(rs);
      lazy[v] = 0;
    }
  }

  void upd(int v, int tl, int tr, int l, int r) {
    if (tr <= l || r <= tl) return;
    if (l <= tl && tr <= r) {
      apply(v);
      return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    upd(lp, l, r);
    upd(rp, l, r);
    st[v] = merge(st[ls], st[rs]);
  }

  void upd(int l, int r) {
    upd(0, 0, n, l, r);
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n, m;
  cin >> n >> m;

  string s;
  cin >> s;

  vector<bool> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = s[i] == '7';
  }

  STree st(n, a);
  for (int i = 0; i < m; i++) {
    string op;
    cin >> op;
    if (op[0] == 's') {
      int l, r;
      cin >> l >> r;
      st.upd(l - 1, r);
    }
    else {
      cout << st.st[0].ans << '\n';
    }
  }

  return 0;
}