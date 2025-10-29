#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1e6 + 1;

vector<int> g[maxn];
int sz[maxn];

void dfs_precalc(int u, int p) {
  sz[u] = 1;
  for (int v : g[u]) {
    if (v != p) {
      dfs_precalc(v, u);
      sz[u] += sz[v];
    }
  }
}

int n;
bool ok(int k) {
  int c = 0;
  for (int i = 0; i < n; ++i) {
    c += sz[i] % k == 0;
  }
  return c == n / k;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n;

  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >>u  >> v;
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs_precalc(0, -1);

  for (int i = 2; i <= n; ++i) {
    if (n % i == 0 && ok(n / i)) {
      cout << i - 1 << ' ';
    }
  }
  cout << '\n';
}