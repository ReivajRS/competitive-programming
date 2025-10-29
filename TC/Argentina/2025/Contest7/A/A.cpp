#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) (int(x.size()))
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

struct STree {
  #define ls st[v].l
  #define rs st[v].r
  #define lp ls, tl, tm
  #define rp rs, tm, tr

  struct Node {
    int l, r, pref, suff, ans;
    Node(int l, int r, int pref, int suff, int ans)
    : l(l), r(r), pref(pref), suff(suff), ans(ans) {}
  };

  void merge(Node& v, Node l, Node r, int tl, int tr) {
    int tm = (tl + tr) / 2;
    int pref = l.pref, suff = r.suff;
    if (l.pref == tm - tl) {
      pref += r.pref;
    }
    if (r.suff == tr - tm) {
      suff += l.suff;
    }
    int ans = max({l.ans, r.ans, l.suff + r.pref});
    v.pref = pref;
    v.suff = suff;
    v.ans = ans;
  };

  int n;
  vector<Node> st;

  STree(int n) : n(n), st(1, Node(0, 0, 0, 0, 0)) {}

  Node query(int v, int tl, int tr, int l, int r) {
    if (tr <= l || r <= tl) return Node(0, 0, 0, 0, 0);
    if (l <= tl && tr <= r) return st[v];
    int tm = (tl + tr) / 2;
    Node x = Node(0, 0, 0, 0, 0);
    merge(x, query(lp, l, r), query(rp, l, r), tl, tr);
    return x;
  }

  int upd(int v, int tl, int tr, int i) {
    st.emplace_back(st[v].l, st[v].r, st[v].pref, st[v].suff, st[v].ans);
    v = int(st.size()) - 1;
    if (tl + 1 == tr) {
      st[v].pref = st[v].suff = st[v].ans = 1;
      return v;
    }
    int tm = (tl + tr) / 2;
    if (i < tm) ls = upd(lp, i);
    else rs = upd(rp, i);
    merge(st[v] ,st[ls], st[rs], tl, tr);
    return v;
  }

  Node query(int root, int l, int r) {
    return query(root, 0, n, l, r);
  }

  int upd(int root, int i) {
    return upd(root, 0, n, i);
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  map<int, int> idx, value;
  vector<int> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }

  vector<int> h2 = h;
  sort(h2.begin(), h2.end());

  for (int i = 0; i < n; i++) {
    if (!idx.count(h2[i])) {
      idx[h2[i]] = int(idx.size());
      value[idx[h2[i]]] = h2[i];
    }
  }
  
  STree st(n);

  int diff = int(idx.size());
  vector<vector<int>> pos_values(diff);
  for (int i = 0; i < n; i++) {
    pos_values[idx[h[i]]].push_back(i);
  }

  vector<int> root(diff);

  for (int v = diff - 1; v >= 0; v--) {
    for (auto i : pos_values[v]) {
      root[v] = st.upd(root[v], i);
    }
    if (v - 1 >= 0) {
      root[v - 1] = root[v];
    }
  }

  int q;
  cin >> q;

  while (q--) {
    int l, r, w;
    cin >> l >> r >> w;

    int lo = 0, hi = diff - 1;
    while (lo < hi) {
      int mid = (lo + hi + 1) / 2;
      if (st.query(root[mid], l - 1, r).ans >= w) {
        lo = mid;
      }
      else {
        hi = mid - 1;
      }
    }

    cout << value[lo] << '\n';
  }

  return 0;
}