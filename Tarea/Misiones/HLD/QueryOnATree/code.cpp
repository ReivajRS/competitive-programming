#include <bits/stdc++.h>
using namespace std;
using edge = tuple<int, int, int>;

struct STree {
  #define ls 2 * v + 1
  #define rs 2 * v + 2
  #define lp ls, tl, tm
  #define rp rs, tm, tr
  #define NEUT 0
  
  int n;
  vector<int> st;

  STree(int n) : n(n), st(4 * n) {}

  int query(int v, int tl, int tr, int l, int r) {
    if (tr <= l || r <= tl) return NEUT;
    if (l <= tl && tr <= r) return st[v];
    int tm = (tl + tr) / 2;
    return max(query(lp, l, r), query(rp, l, r));
  }
  
  void upd(int v, int tl, int tr, int i, int val) {
    if (tl + 1 == tr) { st[v] = val; return; }
    int tm = (tl + tr) / 2;
    if (i < tm) upd(lp, i, val);
    else upd(rp, i, val);
    st[v] = max(st[ls], st[rs]);
  }
 
  int query(int l, int r) {
    return query(0, 0, n, l, r);
  }
  void upd(int i, int val) {
    upd(0, 0, n, i, val);
  }
};

struct HLD {
  int n;
  vector<vector<edge>> g;
  vector<int> sz, depth, parent, head, pos, value, node;
  STree st;
  void init_dfs(int u, int p) {
    parent[u] = p;
    sz[u] = 1;
    int mx_sz = -1;
    for (auto& ti : g[u]) {
      auto &[v, w, i] = ti;
      if (v == p) {
        continue;
      }
      depth[v] = depth[u] + 1;
      value[v] = w;
      node[i] = v;
      init_dfs(v, u);
      sz[u] += sz[v];
      if (sz[v] > mx_sz) {
        mx_sz = sz[v];
        swap(ti, g[u][0]);
      }
    }
  }
  void decompose(int u, int h, int& t) {
    head[u] = h;
    pos[u] = t++;
    for (auto& [v, w, i] : g[u]) {
      if (v == parent[u]) {
        continue;
      }
      if (v == get<0>(g[u][0])) {
        decompose(v, head[u], t);
      }
      else {
        decompose(v, v, t);
      }
    }
  }
  HLD(vector<vector<edge>>& g, int root)
  : n(int(g.size())), g(g), sz(n), depth(n), parent(n), head(n), pos(n), value(n), node(n), st(n) {
    init_dfs(root, -1);
    int t = 0;
    decompose(root, root, t);
    for (int i = 0; i < n; i++) {
      st.upd(pos[i], value[i]);
    }
  }
  int query(int u, int v) {
    int ans = 0;
    while (head[u] != head[v]) {
      if (depth[head[u]] > depth[head[v]]) {
        swap(u, v);
      }
      int heavy_path_ans = st.query(pos[head[v]], pos[v] + 1);
      ans = max(ans, heavy_path_ans);
      v = parent[head[v]];
    }
    if (depth[u] > depth[v]) {
      swap(u, v);
    }
    int heavy_path_ans = st.query(pos[u] + 1, pos[v] + 1);
    ans = max(ans, heavy_path_ans);
    return ans;
  }
  void update(int u, int val) {
    st.upd(pos[node[u]], val);
  }
};

void solve() {
  int n;
  cin >> n;

  vector<vector<edge>> g(n);

  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    g[u].push_back({v, w, i});
    g[v].push_back({u, w, i});
  }

  HLD hld(g, 0);

  while (true) {
    string s;
    cin >> s;
    if (s[0] == 'D') {
      break;
    }
    if (s[0] == 'C') {
      int i, ti;
      cin >> i >> ti;
      hld.update(i - 1, ti);
    }
    else {
      int a, b;
      cin >> a >> b;
      cout << hld.query(a - 1, b - 1) << '\n';
    }
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }

  return 0;
}