#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int maxn = 4e5 + 1;
vector<pair<int, int>> g[maxn];
int ls[maxn], rs[maxn];

struct STree {
  int n, root1, root2;
  int build1(int& idx, int tl, int tr) {
    if (tl + 1 == tr) {
      return tl;
    }
    int tm = (tl + tr) / 2;
    int now_idx = idx++;
    int l_idx = build1(idx, tl, tm);
    int r_idx = build1(idx, tm, tr);
    g[now_idx].push_back({l_idx, 0});
    g[now_idx].push_back({r_idx, 0});
    ls[now_idx] = l_idx;
    rs[now_idx] = r_idx;
    return now_idx;
  }
  int build2(int& idx, int tl, int tr) {
    if (tl + 1 == tr) {
      return tl;
    }
    int tm = (tl + tr) / 2; 
    int now_idx = idx++;
    int l_idx = build2(idx, tl, tm);
    int r_idx = build2(idx, tm, tr);
    g[l_idx].push_back({now_idx, 0});
    g[r_idx].push_back({now_idx, 0});
    ls[now_idx] = l_idx;
    rs[now_idx] = r_idx;
    return now_idx;
  }
  void insert1(int idx, int tl, int tr, int l, int r, int u, int w) {
    if (tr <= l || r <= tl) {
      return;
    }
    if (l <= tl && tr <= r) {
      g[u].push_back({idx, w});
      return;
    }
    int tm = (tl + tr) / 2;
    insert1(ls[idx], tl, tm, l, r, u, w);
    insert1(rs[idx], tm, tr, l, r, u, w);
  }
  void insert2(int idx, int tl, int tr, int l, int r, int u, int w) {
    if (tr <= l || r <= tl) {
      return;
    }
    if (l <= tl && tr <= r) {
      g[idx].push_back({u, w});
      return;
    }
    int tm = (tl + tr) / 2;
    insert2(ls[idx], tl, tm, l, r, u, w);
    insert2(rs[idx], tm, tr, l, r, u, w);
  }
  STree(int n) : n(n) {
    int idx = n;
    root1 = idx;
    build1(idx, 0, n);
    root2 = idx;
    build2(idx, 0, n);
  }
  void insert1(int l, int r, int u, int w) {
    insert1(root1, 0, n, l, r, u, w);
  }
  void insert2(int l, int r, int u, int w) {
    insert2(root2, 0, n, l, r, u, w);
  }
};


signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q, s;
  cin >> n >> q >> s;

  STree st(n);

  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int u, v, w;
      cin >> u >> v >> w;
      u--, v--;
      g[u].push_back({v, w});
      continue;
    }
    int u, l, r, w;
    cin >> u >> l >> r >> w;
    u--, l--;
    if (t == 2) {
      st.insert1(l, r, u, w);
    }
    else {
      st.insert2(l, r, u, w);
    }
  }

  constexpr ll INF = 1e18;

  priority_queue<pair<ll, int>> pq;
  vector<ll> dist(maxn, INF);
  s--;
  dist[s] = 0;
  pq.push({0, s});

  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    d *= -1;
    if (d > dist[u]) {
      continue;
    }
    for (auto [v, w] : g[u]) {
      if (d + w < dist[v]) {
        dist[v] = d + w;
        pq.push({-dist[v], v});
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (dist[i] == INF) {
      dist[i] = -1;
    }
    cout << dist[i] << ' ';
  }
  cout << '\n';

  return 0;
}