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

void divide(int l, int r, vector<Event> events, DSU &dsu, vector<int> &ans) {
  // printf("Node [%d, %d)\n", l, r);
  // for (auto &event : events) {
  //   printf("(%d, %d), [%d, %d)\n", event.a, event.b, event.in, event.out);
  // }
  int t = dsu.time();
  if (l + 1 == r) {
    for (auto &event : events) {
      dsu.join(event.a, event.b);
    }
    ans[l] = dsu.comps;
    dsu.rollback(t);
    return;
  }
  int m = (l + r) >> 1;
  vector<Event> l_events, r_events;
  for (auto &event : events) {
    if (event.in <= l && r <= event.out) {
      dsu.join(event.a, event.b);
      continue;
    }
    if (event.out <= m || event.in < m) {
      l_events.push_back(event);
    }
    if (event.in >= m || event.out > m) {
      r_events.push_back(event);
    }
  }
  divide(l, m, l_events, dsu, ans);
  divide(m, r, r_events, dsu, ans);
  dsu.rollback(t);
}

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

  vector<int> ans(k + 1);
  DSU dsu(n);

  divide(0, k + 1, events, dsu, ans);

  for (int i = 0; i <= k; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';

  return 0;
}