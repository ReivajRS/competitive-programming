#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

using Update = tuple<int, int, int, int>;

struct RollbackDSU {
  bool isBipartite;
  vector<int> e;
  vector<pair<int, int>> st;
  RollbackDSU(int n) : isBipartite(true), e(n, -1) {}
  int get(int x) {
    return e[x] < 0 ? x : get(e[x]);
  }
  int time() {
    return SZ(st);
  }
  void rollback(int t) {
    for (int i = time(); i-- > t;) {
      e[st[i].first] = st[i].second;
    }
    st.resize(t);
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
};

int n, m;

void dnc(int L, int R, vector<Update>& upd, RollbackDSU& dsu, vector<bool>& ans) {
  cout << L << ' ' << R << '\n';
  int startTime = dsu.time(), M = (L + R) >> 1;
  bool wasBipartite = dsu.isBipartite;
  vector<Update> updL, updR;
  for (Update& update : upd) {
    auto [l, r, u, v] = update;
    if (l <= L && R <= r) {
      cout << " inside " << l << ' ' << r << ' ' << u << ' ' << v << '\n';
      if (dsu.get(u) == dsu.get(v)) {
        dsu.isBipartite = false;
        cout << " no longer bipartite\n";
      } else {
        dsu.join(u, v + n);
        dsu.join(u + n, v);
      }
    } else {
      if (l < M) {
        updL.push_back(update);
      }
      if (r > M) {
        updR.push_back(update);
      }
    }
  }
  if (L + 1 == R) {
    ans[L] = dsu.isBipartite;
  } else {
    dnc(L, M, updL, dsu, ans), dnc(M, R, updR, dsu, ans);
  }
  dsu.rollback(startTime);
  dsu.isBipartite = wasBipartite;
}
 
signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> m;

  vector<Update> upd;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    if (i) {
      upd.emplace_back(0, i, u, v);
    }
    if (i != m - 1) {
      upd.emplace_back(i + 1, m, u, v);
    }
  }

  vector<bool> ans(m);
  RollbackDSU dsu(2 * n);
  dnc(0, m, upd, dsu, ans);

  vector<int> ansEdges;
  for (int i = 0; i < m; ++i) {
    if (ans[i]) {
      ansEdges.push_back(i);
    }
  }
  
  cout << ansEdges.size() << '\n';
  for (int i : ansEdges) {
    cout << i + 1 << ' ';
  }
  cout << '\n';

  return 0;
}