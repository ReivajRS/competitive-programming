#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

constexpr int MOD = 1e9 + 7, MAXN = 2e5 + 1;
vi g[MAXN];
ll sz[MAXN];
bool vis[MAXN];
ll n;

ll binpow(ll a, ll b, ll m = MOD) {
  ll res = 1;
  a %= m;
  while (b) {
    if (b & 1) {
      res = (res * a) % m;
    }
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}

ll inv(ll a) {
  return binpow(a, MOD - 2) % MOD;
}

int get_subtree_size(int u, int p = -1) {
  sz[u] = 1;
  for (auto &v : g[u]) {
    if (v == p) {
      continue;
    }
    sz[u] += get_subtree_size(v, u);
  }
  return sz[u];
}

ll get_path_sum(int u, int p = -1) {
  ll sum = 0;
  for (auto &v : g[u]) {
    if (v == p) {
      continue;
    }
    sum = (sum + sz[v] * (n - sz[v])) % MOD;
    sum = (sum + get_path_sum(v, u)) % MOD;
  }
  return sum;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n;

  FOR (i, 0, n - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }

  get_subtree_size(0);
  ll p = get_path_sum(0) % MOD;
  ll q = n * (n + 1) / 2 % MOD;

  cout << p * inv(q) % MOD << ENDL;
  
  return 0;
}