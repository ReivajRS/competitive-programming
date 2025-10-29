#include <bits/stdc++.h>
using namespace std;

struct DSU {
  vector<int> e;
  stack<pair<int, int>> st;
  int comps;
  DSU(int n) : e(n, -1), comps(n) {}
  int get(int x) {
    return e[x] < 0 ? x : get(e[x]);
  }
  bool join(int a, int b) {
    a = get(a), b = get(b);
    if (a == b) {
      return false;
    }
    if (e[a] > e[b]) {
      swap(a, b);
    }
    st.push({a, e[a]});
    st.push({b, e[b]});
    e[a] += e[b];
    e[b] = a;
    comps--;
    return true;
  }
  int time() {
    return (int)st.size();
  }
  void rollback(int t) {
    comps += (time() - t) >> 1;
    while (time() > t) {
      auto &[i, old] = st.top();
      e[i] = old;
      st.pop();
    }
  }
};

void divide(int l, int r, vector<tuple<char, int, int, int, int>> &events, DSU &A, DSU &AB, vector<int> &ans) {
  int t_A = A.time();
  int t_AB = AB.time();
  for (auto &[c, u, v, le, re] : events) {
    if (le <= l && r <= re) {
      if (c == 'A') {
        A.join(u, v);
      }
      AB.join(u, v);
    }
  }
  if (l + 1 == r) {
    ans[l] = A.comps - AB.comps;
    A.rollback(t_A);
    AB.rollback(t_AB);
    return;
  }
  int m = (l + r) >> 1;
  vector<tuple<char, int, int, int, int>> l_events, r_events;
  for (auto &event : events) {
    int le = get<3>(event), re = get<4>(event);
    if (le <= l && r <= re) {
      continue;
    }
    if (re <= m || le < m) {
      l_events.push_back(event);
    }
    if (le >= m || re > m) {
      r_events.push_back(event);
    }
  }
  divide(l, m, l_events, A, AB, ans);
  divide(m, r, r_events, A, AB, ans);
  A.rollback(t_A);
  AB.rollback(t_AB);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;

  vector<tuple<char, int, int, int, int>> events;
  map<tuple<char, int, int>, int> mp;

  for (int i = 0; i < q; i++) {
    char c;
    int u, v;
    cin >> c >> u >> v;
    u--, v--;
    if (u > v) {
      swap(u, v);
    }
    tuple<char, int, int> key = {c, u, v};
    if (mp.count(key)) {
      events.push_back({c, u, v, mp[key], i});
      mp.erase(key);
    }
    else {
      mp[key] = i;
    }
  }

  for (auto &[key, t] : mp) {
    auto &[c, u, v] = key;
    events.push_back({c, u, v, t, q});
  }
  mp.clear();

  DSU A(n), AB(n);
  vector<int> ans(q);

  divide(0, q, events, A, AB, ans);

  for (int i = 0; i < q; i++) {
    cout << ans[i] << '\n';
  }

  return 0;
}