#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int maxn = 1e6 + 1;
bool is_prime[maxn];

void sieve(int n) {
  fill(is_prime, is_prime + maxn, 1);
  is_prime[0] = is_prime[1] = 0;
  for (ll p = 2; p <= n; p++) {
    if(!is_prime[p])continue;
    for(ll i=p*p;i<=n;i+=p)is_prime[i]=0;
  }
}

void solve() {
  int n;
  cin >> n;

  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  set<int> st;
  for (int i = 1; i <= 2 * n; i++) {
    st.insert(i);
  }

  vector<int> a(n);
  vector<int> next(n, 1);

  auto dfs = [&](auto &self, int u, int p = -1) -> void {
    auto it = p == -1 ? st.begin() : st.lower_bound(next[p]);
    while (p != -1 && it != st.end() && is_prime[abs(a[p] - *it)]) {
      it++;
    }
    if (it == st.end()) {
      cout << "-1" << '\n';
      exit(0);
    }
    if (p != -1) {
      next[p] = *it;
    }
    a[u] = *it;
    st.erase(it);
    for (auto v : g[u]) if (v != p) {
      self(self, v, u);
    }
  };

  dfs(dfs, 0);

  for (int i = 0; i < n; i++) {
    cout << a[i] << " \n"[i == n - 1];
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  sieve(maxn);

  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }

  return 0;
}