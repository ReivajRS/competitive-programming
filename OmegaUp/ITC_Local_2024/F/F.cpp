#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

struct DSU {
  vector<int> p, sz;
  DSU(int n) : p(n), sz(n, 1) {
    iota(p.begin(), p.end(), 0);
  }
  int get(int x) {
    return p[x] == x ? x : p[x] = get(p[x]);
  }
  bool join(int a, int b) {
    a = get(a), b = get(b);
    if (a == b) return false;
    if (sz[b] > sz[a]) swap(a, b);
    p[b] = a;
    sz[a] += sz[b];
    return true;
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  map<string, int> mp;

  vector<tuple<int, int, int, int, int>> events;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    string s, t;
    cin >> s >> t;
    if (!mp.count(s)) mp[s] = SZ(mp);
    if (!mp.count(t)) mp[t] = SZ(mp);
    events.push_back({x, 0, mp[s], mp[t], -1});
  }

  int q;
  cin >> q;

  vector<bool> ans(q);

  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;
    string s, t;
    cin >> s >> t;
    if (!mp.count(s)) mp[s] = SZ(mp);
    if (!mp.count(t)) mp[t] = SZ(mp);
    events.push_back({x, 1, mp[s], mp[t], i});
  }

  sort(events.begin(), events.end());

  DSU dsu(SZ(mp));

  for (auto [year, type, id1, id2, nq] : events) {
    if (type == 0) {
      dsu.join(id1, id2);
      continue;
    }
    ans[nq] = dsu.get(id1) == dsu.get(id2);
  }

  for (auto x : ans) {
    cout << (x ? "Si" : "No") << '\n';
  }

  return 0;
}