#include <bits/stdc++.h>
using namespace std;

struct DSU {
  vector<int> e;
  vector<pair<int, int>> st;
  int comps;
  DSU(int n) : e(n, -1), comps(n) {}
  int get(int x) { return e[x] < 0 ? x : get(e[x]); }
  int size(int x) { return -e[get(x)]; }
  int time() { return (int)st.size(); }
  void rollback(int t) {
    comps += (time() - t) / 2;
    while (time() > t) {
      auto [i, old] = st.back();
      e[i] = old;
      st.pop_back();
    }
  }
  bool join(int a, int b) {
    a = get(a), b = get(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    st.push_back({a, e[a]});
    st.push_back({b, e[b]});
    e[a] += e[b];
    e[b] = a;
    comps--;
    return true;
  }
};

struct Event {
  int a, b, in, out;
};

struct STree {
  #define lc (k << 1) + 1
  #define rc (k << 1) + 2
  #define lp lc, l, m
  #define rp rc, m, r

  struct Node {
    vector<pair<int, int>> edges;
    Node() {}
  };

  const Node NEUT = Node();
  int n;
  vector<Node> st;

  void add(Event &event, int k, int l, int r) {
    if (r <= event.in || l >= event.out) {
      return;
    }
    if (event.in <= l && r <= event.out) {
      st[k].edges.push_back({event.a, event.b});
      return;
    }
    int m = (l + r) >> 1;
    add(event, lp);
    add(event, rp);
  }

  void dfs(int k, int l, int r, vector<int> &ans, DSU &dsu) {
    int t = dsu.time();
    for (auto [a, b] : st[k].edges) {
      dsu.join(a, b);
    }
    if (l + 1 == r) {
      ans[l] = dsu.comps;
      dsu.rollback(t);
      return;
    }
    int m = (l + r) >> 1;
    dfs(lp, ans, dsu);
    dfs(rp, ans, dsu);
    dsu.rollback(t);
  }

  STree(int _n) : n(_n), st((n << 2) + 1, NEUT) {}
  void add(Event &event) {
    add(event, 0, 0, n);
  }
  void dfs(vector<int> &ans, DSU &dsu) {
    dfs(0, 0, n, ans, dsu);
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m, k;
  cin >> n >> m >> k;

  vector<Event> events;
  map<pair<int, int>, int> pending;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    pending[{min(a, b), max(a, b)}] = 0;
  }

  for (int i = 1; i <= k; i++) {
    int t, a, b;
    cin >> t >> a >> b;
    a--, b--;
    pair<int, int> p = {min(a, b), max(a, b)};
    if (t == 1) {
      pending[p] = i;
    }
    else {
      int in = pending[p];
      events.push_back(Event{p.first, p.second, in, i});
      pending.erase(p);
    }
  }

  for (auto [p, in] : pending) {
    events.push_back(Event{p.first, p.second, in, k + 1});
  }
  pending.clear();

  STree st(k + 1);
  for (auto event : events) {
    st.add(event);
  }

  vector<int> ans(k + 1);
  DSU dsu(n);

  st.dfs(ans, dsu);

  for (int i = 0; i <= k; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';

  return 0;
}