#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy y la Alexbriza 

using ll = long long;

struct Data {
  ll mx;
  int i;
  
  Data() : mx(0), i(0) {}
  Data(ll mx, int i) : mx(mx), i(i) {}

  Data operator+(const Data& other) const {
    if (mx != other.mx) {
      return mx > other.mx ? *this : other;
    }
    return Data(
      mx,
      min(i, other.i)
    );
  }
};

struct STree {
  #define ls st[v].l
  #define rs st[v].r
  #define lp ls, tl, tm
  #define rp rs, tm, tr

  struct Node {
    Data data;
    int l, r;

    Node(Data data = Data()) : data(data), l(-1), r(-1) {}
  };

  Data getData(int v) {
    return v == -1 ? Data() : st[v].data;
  }

  int n;
  vector<Node> st;

  STree(int n) : n(n), st(1) {}

  int increment(int v, int tl, int tr, int i, ll x) {
    if (v == -1) {
      v = int(st.size());
      st.emplace_back();
    }
    if (tl + 1 == tr) {
      st[v].data = Data(st[v].data.mx + x, i);
      return v;
    }
    int tm = (tl + tr) >> 1;
    (i < tm) ? ls = increment(lp, i, x) : rs = increment(rp, i, x);
    st[v].data = getData(ls) + getData(rs);
    return v;
  }

  void increment(int i, ll x) { increment(0, 0, n, i, x); }
  Data query() { return st[0].data; }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int N;
  cin >> N;

  vector<int> T(N);
  for (int i = 1; i < N; ++i) {
    cin >> T[i];
  }

  vector<vector<int>> adj(N);
  for (int i = 1; i < N; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v), adj[v].push_back(u);
  }

  int t = -1;
  vector<int> sz(N), in(N), out(N), depth(N), tour;
  auto precalc = [&](auto&& self, int u, int p = -1) -> int {
    if (p != -1) {
      adj[u].erase(find(adj[u].begin(), adj[u].end(), p));
    }
    tour.push_back(u);
    in[u] = ++t;
    sz[u] = 1;
    for (int& v : adj[u]) {
      depth[v] = depth[u] + 1;
      sz[u] += self(self, v, u);
      if (sz[v] > sz[adj[u][0]]) {
        swap(v, adj[u][0]);
      }
    }
    out[u] = t;
    return sz[u];
  };
  precalc(precalc, 0);

  auto solve = [&](auto&& self, STree& st, int u, bool leave = false) -> pair<ll, int> {
    pair<ll, int> answer = {T[u], -1};
    if (adj[u].empty()) {
      if (leave) {
        st.increment(depth[u], T[u]);
      }
      return answer;
    }
    for (int i = 1; i < int(adj[u].size()); ++i) {
      answer = max(answer, self(self, st, adj[u][i]));
    }
    answer = max(answer, self(self, st, adj[u][0], true));
    st.increment(depth[u], T[u]);
    for (int i = 1; i < int(adj[u].size()); ++i) {
      int v = adj[u][i];
      for (int j = in[v]; j <= out[v]; ++j) {
        int x = tour[j];
        st.increment(depth[x], T[x]);
      }
    }
    auto [best, i] = st.query();
    answer = max(answer, {best, -(i - depth[u] + 1)});
    if (!leave) {
      st = STree(N);
    }
    return answer;
  };
  STree st(N);
  auto [best, i] = solve(solve, st, 0);
  cout << best << ' ' << -i << '\n';
}