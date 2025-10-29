#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct STree {
  #define ls 2 * v + 1
  #define rs 2 * v + 2
  #define lp ls, tl, tm
  #define rp rs, tm, tr
  #define NEUT 0

  int n;
  vector<ll> st;

  STree(int n) : n(n), st(4 * n) {}

  ll query(int v, int tl, int tr, int l, int r) {
    if (tr <= l || r <= tl) return NEUT;
    if (l <= tl && tr <= r) return st[v];
    int tm = (tl + tr) / 2;
    return query(lp, l, r) + query(rp, l, r);
  }
  
  void upd(int v, int tl, int tr, int i, ll val) {
    if (tl + 1 == tr) { st[v] = val; return; }
    int tm = (tl + tr) / 2;
    if (i < tm) upd(lp, i, val);
    else upd(rp, i, val);
    st[v] = st[ls] + st[rs];
  }
 
  ll query(int l, int r) {
    return query(0, 0, n, l, r);
  }
  void upd(int i, ll val) {
    upd(0, 0, n, i, val);
  }
};

struct HLD {
  int n;
  vector<vector<int>> g;
  vector<int> sz, depth, parent, head, pos;
  STree st;
  void init_dfs(int u, int p) {
    parent[u] = p;
    sz[u] = 1;
    int mx_sz = -1;
    for (auto& v : g[u]) {
      if (v != p) {
        depth[v] = depth[u] + 1;
        init_dfs(v, u);
        sz[u] += sz[v];
      }
      if (sz[v] > mx_sz) {
        mx_sz = sz[v];
        swap(v, g[u][0]);
      }
    }
  }
  void decompose(int u, int h, int& t) {
    head[u] = h;
    pos[u] = t++;
    for (auto& v : g[u]) {
      if (v == parent[u]) {
        continue;
      }
      if (v == g[u][0]) {
        decompose(v, head[u], t);
      }
      else {
        decompose(v, v, t);
      }
    }
  }
  HLD(vector<vector<int>>& g, vector<int>& val, int root) : n(int(g.size())), g(g), sz(n), depth(n), parent(n), head(n), pos(n), st(n) {
    init_dfs(root, -1);
    int t = 0;
    decompose(root, root, t);
    for (int i = 0; i < n; i++) {
      st.upd(pos[i], val[i]);
    }
  }
  ll query(int u, int v) {
    ll ans = 0;
    while (head[u] != head[v]) {
      if (depth[head[u]] > depth[head[v]]) {
        swap(u, v);
      }
      ll heavy_path_ans = st.query(pos[head[v]], pos[v] + 1);
      ans += heavy_path_ans;
      v = parent[head[v]];
    }
    if (depth[u] > depth[v]) {
      swap(u, v);
    }
    ll heavy_path_ans = st.query(pos[u], pos[v] + 1);
    ans += heavy_path_ans;
    return ans;
  }
  void update(int u, ll val) {
    st.upd(pos[u], val);
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;

  vector<int> val(n);
  for (int i = 0; i < n; i++) {
    cin >> val[i];
  }

  vector<vector<int>> g(n);

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  HLD hld(g, val, 0);

  while (q--) {
    int t, s;
    cin >> t >> s;
    s--;
    if (t == 1) {
      int x;
      cin >> x;
      hld.update(s, x);
    }
    else {
      cout << hld.query(0, s) << '\n';
    }
  }

  return 0;
}