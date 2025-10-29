#include <bits/stdc++.h>
using namespace std;

struct DSU {
  vector<int> e;
  vector<pair<int, int>> st;
  DSU(int n) : e(n, -1) {}
  int get(int x) {
    return e[x] < 0 ? x : get(e[x]);
  }
  int size(int x) {
    return -e[get(x)];
  }
  bool join(int a, int b) {
    a = get(a), b = get(b);
    if (a == b) {
      return false;
    }
    if (e[a] > e[b]) {
      swap(a, b);
    }
    st.push_back({a, e[a]});
    st.push_back({b, e[b]});
    e[a] += e[b];
    e[b] = a;
    return true;
  }
  int time() {
    return (int)st.size();
  }
  void rollback(int t) {
    while (time() > t) {
      auto [i, old] = st.back();
      e[i] = old;
      st.pop_back();
    }
  }
  bool is_connected() {
    return size(0) == (int)e.size();
  }
};

void divide(int l, int r, vector<tuple<int, int, int>> &events, vector<pair<int, int>> &edges, DSU &dsu, vector<int> &ans) {
  int t = dsu.time();
  if (l + 1 == r) {
    for (auto &[x, le, re] : events) {
      dsu.join(edges[x].first, edges[x].second);
    }
    ans[l] = dsu.is_connected();
    dsu.rollback(t);
    return;
  }

  int m = (l + r) >> 1;
  vector<tuple<int, int, int>> l_events, r_events;
  for (auto &event : events) {
    auto &[x, le, re] = event;
    if (le <= l && r <= re) {
      dsu.join(edges[x].first, edges[x].second);
      continue;
    }
    if (re <= m || le < m) {
      l_events.push_back(event);
    }
    if (le >= m || re > m) {
      r_events.push_back(event);
    }
  }
  
  divide(l, m, l_events, edges, dsu, ans);
  divide(m, r, r_events, edges, dsu, ans);
  dsu.rollback(t);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  freopen("disconnected.in", "r", stdin);
  freopen("disconnected.out", "w", stdout);

  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> edges(m);
  vector<int> last_time(m, 0);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (u > v) {
      swap(u, v);
    }
    edges[i] = {u, v};
  }

  vector<tuple<int, int, int>> events;
  int k;
  cin >> k;
  for (int i = 1; i <= k; i++) {
    int c;
    cin >> c;
    for (int j = 0; j < c; j++) {
      int x;
      cin >> x;
      x--;
      if (last_time[x] < i) {
        events.push_back({x, last_time[x], i});
      }
      last_time[x] = i + 1;
    }
  }

  for (int i = 0; i < m; i++) {
    if (last_time[i] <= k) {
      events.push_back({i, last_time[i], k + 1});
    }
  }

  DSU dsu(n);
  vector<int> ans(k + 1);

  divide(0, k + 1, events, edges, dsu, ans);

  for (int i = 1; i <= k; i++) {
    cout << (ans[i] ? "Connected" : "Disconnected") << '\n';
  }

  return 0;
}