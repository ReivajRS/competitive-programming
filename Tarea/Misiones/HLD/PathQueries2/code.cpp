#include <bits/stdc++.h>
using namespace std;

struct STree {
  int n;
  vector<int> st;

  STree(int n) : n(n), st(2 * n) {}

  int query(int l, int r) {
    l += n, r += n;
    int ans = 0;
    while (l <= r) {
      if (l % 2 == 1) {
        ans = max(ans, st[l++]);
      }
      if (r % 2 == 0) {
        ans = max(ans, st[r--]);
      }
      l /= 2, r /= 2;
    }
    return ans;
  }

  void upd(int i, int val) {
    i += n;
    st[i] = val;
    for (i /= 2; i >= 1; i /= 2) {
      st[i] = max(st[i * 2], st[i * 2 + 1]);
    }
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
  int query(int u, int v) {
    int ans = 0;
    while (head[u] != head[v]) {
      if (depth[head[u]] > depth[head[v]]) {
        swap(u, v);
      }
      int heavy_path_ans = st.query(pos[head[v]], pos[v]);
      ans = max(ans, heavy_path_ans);
      v = parent[head[v]];
    }
    if (depth[u] > depth[v]) {
      swap(u, v);
    }
    int heavy_path_ans = st.query(pos[u], pos[v]);
    ans = max(ans, heavy_path_ans);
    return ans;
  }
  void update(int u, int val) {
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
    int t;
    cin >> t;
    if (t == 1) {
      int s, x;
      cin >> s >> x;
      hld.update(s - 1, x);
    }
    else {
      int a, b;
      cin >> a >> b;
      cout << hld.query(a - 1, b - 1) << ' ';
    }
  }

  cout << '\n';

  return 0;
}