#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

struct STree {
  #define ls 2 * v + 1
  #define rs 2 * v + 2
  static constexpr ll INF = 1e18 + 5;
  struct Node {
    ll mn, mx, lazy;
    Node() : mn(0), mx(0), lazy(0) {}
    Node(ll mn, ll mx) : mn(mn), mx(mx), lazy(0) {}
  };
  Node merge(Node x, Node y) {
    return Node(min(x.mn, y.mn), max(x.mx, y.mx));
  }
  
  const Node NEUT = Node(INF, -INF);
  int n;
  vector<Node> st;
  STree(int n) : n(n), st(4 * n) {}

  void apply(int v, ll val) {
    st[v].mn += val;
    st[v].mx += val;
    st[v].lazy += val;
  }

  void push(int v) {
    if (st[v].lazy == 0) {
      return;
    }
    apply(ls, st[v].lazy);
    apply(rs, st[v].lazy);
    st[v].lazy = 0;
  }
  
  void update(int v, int tl, int tr, int l, int r, ll val) {
    if (tr <= l || r <= tl) {
      return;
    }
    if (l <= tl && tr <= r) {
      apply(v, val);
      return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    update(ls, tl, tm, l, r, val);
    update(rs, tm, tr, l, r, val);
    st[v] = merge(st[ls], st[rs]);
  }
  Node query(int v, int tl, int tr, int l, int r) {
    if (tr <= l || r <= tl) {
      return NEUT;
    }
    if (l <= tl && tr <= r) {
      return st[v];
    }
    push(v);
    int tm = (tl + tr) / 2;
    return merge(query(ls, tl, tm, l, r), query(rs, tm, tr, l, r));
  }
  void update(int l, int r, ll val) {
    update(0, 0, n, l, r, val);
  }
  Node query(int l, int r) {
    return query(0, 0, n, l, r);
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<ll> idxs;
  vector<tuple<char, int, ll>> a(n);
  for (int i = 0; i < n; i++) {
    char c;
    int l;
    ll p;
    cin >> c >> l >> p;
    a[i] = {c, l, p};
    idxs.push_back(p);
    idxs.push_back(p + 1);
    if (c == '-') {
      idxs.push_back(p + l);
    }
  }

  sort(idxs.begin(), idxs.end());
  idxs.erase(unique(idxs.begin(), idxs.end()), idxs.end());

  auto get_idx = [&idxs](ll x) -> int {
    return int(lower_bound(idxs.begin(), idxs.end(), x) - idxs.begin());
  };

  STree st(SZ(idxs) + 1);

  for (auto [c, l, p] : a) {
    if (c == '|') {
      cout << 'S';
      st.update(get_idx(p), get_idx(p + 1), l);
    }
    else {
      STree::Node node = st.query(get_idx(p), get_idx(p + l));
      if (node.mn == node.mx) {
        cout << 'S';
        st.update(get_idx(p), get_idx(p + l), 1);
      }
      else {
        cout << 'U';
      }
    }
  }
  
  cout << '\n';

  return 0;
}