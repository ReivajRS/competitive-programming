#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;

struct STree {
  struct Node {
    int l, r, min1, min2, lazy;
    Node(int l, int r)
    : l(l), r(r), min1(0), min2(INF), lazy(0) {}
  };
  int n;
  vector<Node> st;
  STree(int n) : n(n), st(1, Node(0, 0)) {}
  void merge(Node& node, Node& x, Node& y) {
    if (x.min1 < y.min1) {
      node.min1 = x.min1;
      node.min2 = min(x.min2, y.min1);
    }
    else if (y.min1 < x.min1) {
      node.min1 = y.min1;
      node.min2 = min(y.min2, x.min1);
    }
    else {
      node.min1 = x.min1;
      node.min2 = min(x.min2, y.min2);
    }
  }
  int clone(int v) {
    st.push_back(st[v]);
    return int(st.size()) - 1;
  }
  void apply(int v, int val) {
    if (val <= st[v].min1) {
      return;
    }
    st[v].min1 = val;
    st[v].lazy = max(st[v].lazy, val);
  }
  void push(int v, int tl, int tr) {
    if (st[v].lazy == 0 || tl + 1 == tr) {
      return;
    }
    st[v].l = clone(st[v].l);
    st[v].r = clone(st[v].r);
    apply(st[v].l, st[v].lazy);
    apply(st[v].r, st[v].lazy);
    st[v].lazy = 0;
  }
  int query(int v, int tl, int tr, int l, int r, int carry = 0) {
    if (tr <= l || r <= tl) {
      return INF;
    }
    carry = max(carry, st[v].lazy);
    if (l <= tl && tr <= r) {
      return max(st[v].min1, carry);
    }
    int tm = (tl + tr) / 2;
    return min(query(st[v].l, tl, tm, l, r, carry), query(st[v].r, tm, tr, l, r, carry));
  }
  int update(int v, int tl, int tr, int l, int r, int val) {
    if (tr <= l || r <= tl || val <= st[v].min1) {
      return v;
    }
    v = clone(v);
    if (l <= tl && tr <= r && val < st[v].min2) {
      apply(v, val);
      return v;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    st[v].l = update(st[v].l, tl, tm, l, r, val);
    st[v].r = update(st[v].r, tm, tr, l, r, val);
    merge(st[v], st[st[v].l], st[st[v].r]);
    return v;
  }
  int query(int root, int l, int r) {
    return query(root, 0, n, l, r);
  }
  int update(int root, int l, int r, int val) {
    return update(root, 0, n, l, r, val);
  }
};

struct Event {
  int a, b, h, in, out;
  Event(int a, int b, int h, int in, int out) : a(a), b(b), h(h), in(in), out(out) {}
  Event() : Event(0, 0, 0, 0, 0) {}
};

void divide(int l, int r, vector<Event> &events, map<int, vector<pair<int, int>>> &queries, map<int, int> &idx, STree &st, int root, vector<int> &ans) {
  for (auto &[a, b, h, in, out] : events) {
    if (in <= l && r <= out) {
      root = st.update(root, idx[a] * 2, idx[b] * 2 + 1, h);
    }
  }
  if (l + 1 == r) {
    for (auto &[a, b] : queries[l]) {
      ans.push_back(st.query(root, idx[a] * 2, idx[b] * 2 + 1));
    }
    return;
  }
  int m = (l + r) / 2;
  vector<Event> l_events, r_events;
  for (auto &event : events) {
    if (event.in <= l && r <= event.out) {
      continue;
    }
    if (event.in < m) {
      l_events.push_back(event);
    }
    if (event.out > m) {
      r_events.push_back(event);
    }
  }
  divide(l, m, l_events, queries, idx, st, root, ans);
  divide(m, r, r_events, queries, idx, st, root, ans);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<int> pos = {0};
  vector<Event> events;
  map<int, vector<pair<int, int>>> queries;
  int t = 0;

  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    if (c == '+') {
      int a, b, h;
      cin >> a >> b >> h;
      a--, b--;
      pos.push_back(a);
      pos.push_back(b);
      events.push_back({a, b, h, ++t, INF});
    }
    else if (c == '?') {
      int l, r;
      cin >> l >> r;
      l--, r--;
      pos.push_back(l);
      pos.push_back(r);
      queries[t].push_back({l, r});
    }
    else {
      int i;
      cin >> i;
      i--;
      events[i].out = ++t;
    }
  }

  for (auto &event : events) {
    if (event.out == INF) {
      event.out = t + 1;
    }
  }

  sort(pos.begin(), pos.end());

  map<int, int> idx;
  for (auto &x : pos) {
    if (!idx.count(x)) {
      idx[x] = (int)idx.size();
    }
  }

  STree st((int)idx.size() * 2 + 1);
  vector<int> ans;
  divide(0, t + 1, events, queries, idx, st, 0, ans);

  for (auto &x : ans) {
    cout << x << '\n';
  }

  return 0;
}