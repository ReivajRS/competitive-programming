#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;
const int MAX_NODES = 1e8;

struct Node {
    int l, r;
    int left = -1, right = -1; // índices
    int min_val, max_val, smin_val;
    int cnt_min;

    Node() = default;
    Node(int _l, int _r, int val) : l(_l), r(_r), min_val(val), max_val(val), smin_val(INF), cnt_min(1) {}
};

vector<Node> pool;
int alloc() {
    pool.emplace_back();
    return (int)pool.size() - 1;
}

int merge(int lidx, int ridx) {
    int id = alloc();
    Node &node = pool[id];
    Node &L = pool[lidx], &R = pool[ridx];

    node.l = L.l;
    node.r = R.r;
    node.left = lidx;
    node.right = ridx;

    node.min_val = min(L.min_val, R.min_val);
    node.max_val = max(L.max_val, R.max_val);

    if (L.min_val < R.min_val) {
        node.cnt_min = L.cnt_min;
        node.smin_val = min(L.smin_val, R.min_val);
    } else if (L.min_val > R.min_val) {
        node.cnt_min = R.cnt_min;
        node.smin_val = min(L.min_val, R.smin_val);
    } else {
        node.cnt_min = L.cnt_min + R.cnt_min;
        node.smin_val = min(L.smin_val, R.smin_val);
    }

    return id;
}

int build(int l, int r, const vector<int>& A) {
    int id = alloc();
    Node &node = pool[id];
    node.l = l;
    node.r = r;

    if (r - l == 1) {
        int val = A[l];
        node.min_val = node.max_val = val;
        node.smin_val = INF;
        node.cnt_min = 1;
        return id;
    }

    int m = (l + r) / 2;
    int lid = build(l, m, A);
    int rid = build(m, r, A);
    return merge(lid, rid);
}

int chmax(int id, int a, int b, int x);

int apply_chmax(int id, int x) {
    Node& node = pool[id];
    if (x <= node.min_val) return id;

    if (node.r - node.l == 1) {
        int nid = alloc();
        Node& res = pool[nid];
        res = node;
        res.min_val = res.max_val = x;
        res.smin_val = INF;
        res.cnt_min = 1;
        return nid;
    }

    int lnew = chmax(pool[id].left, node.l, node.r, x);
    int rnew = chmax(pool[id].right, node.l, node.r, x);
    return merge(lnew, rnew);
}

int chmax(int id, int a, int b, int x) {
    Node &node = pool[id];
    if (b <= node.l || node.r <= a || x <= node.min_val) return id;

    int nid = alloc();
    pool[nid] = node;
    Node &new_node = pool[nid];

    if (a <= new_node.l && new_node.r <= b && new_node.smin_val > x) {
        return apply_chmax(nid, x);
    }

    new_node.left = chmax(node.left, a, b, x);
    new_node.right = chmax(node.right, a, b, x);
    return merge(new_node.left, new_node.right);
}

int query_min(int id, int a, int b) {
    Node &node = pool[id];
    if (b <= node.l || node.r <= a) return INF;
    if (a <= node.l && node.r <= b) return node.min_val;
    return min(query_min(node.left, a, b), query_min(node.right, a, b));
}

struct Event {
  int a, b, h, in, out;
  Event(int a, int b, int h, int in, int out) : a(a), b(b), h(h), in(in), out(out) {}
  Event() : Event(0, 0, 0, 0, 0) {}
};

void divide(int l, int r, vector<Event> &events, map<int, vector<pair<int, int>>> &queries, map<int, int> &idx, int root, vector<int> &ans) {
  for (auto &[a, b, h, in, out] : events) {
    if (in <= l && r <= out) {
      root = chmax(root, idx[a] * 2, idx[b] * 2 + 1, h); 
    }
  }
  if (l + 1 == r) {
    for (auto &[a, b] : queries[l]) {
      ans.push_back(query_min(root, idx[a] * 2, idx[b] * 2 + 1));
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
  divide(l, m, l_events, queries, idx, root, ans);
  divide(m, r, r_events, queries, idx, root, ans);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<int> pos = {0};
  vector<Event> events;
  map<int, vector<pair<int, int>>> queries;
  int t = 0;
  const int INF = 1e9 + 5;

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

  pool.reserve(MAX_NODES);
  vector<int> ini((int)idx.size() * 2 + 2, 0);
  int root = build(0, (int)ini.size(), ini);

  vector<int> ans;
  divide(0, t + 2, events, queries, idx, root, ans);

  for (auto &x : ans) {
    cout << x << '\n';
  }

  return 0;
}