#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define Aint(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 8001;

int a[MAXN], b[MAXN], nb[MAXN], c[MAXN][MAXN], updating[MAXN], updates[MAXN];
bool vis[MAXN];
vi g[MAXN], ts;
int n, m, E, k, q = 0, act = 0, cnt_updates = 1, sz_updates = 0, total = 0;

void get_ts(int u) {
  vis[u] = 1;
  for (auto &v : g[u]) if (!vis[v]) {
    get_ts(v);
  }
  ts.pb(u);
}

void count_paths() {
  for (auto &u : ts) {
    c[u][u] = 1;
    for (auto &v : g[u]) {
      FOR (i, 0, n) {
        c[u][i] += c[v][i];
        if (c[u][i] >= MOD) c[u][i] -= MOD;
      }
    }
  }
}

void init_values() {
  for (auto &u : ts) {
    for (auto &v : g[u]) {
      a[u] += a[v];
      if (a[u] >= MOD) a[u] -= MOD;
    }
  }
}

void calc_values() {
  FOR (i, 0, n) a[i] = b[i];
  init_values();
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  cin >> n;

  FOR (i, 0, n) cin >> b[i];

  cin >> m;

  FOR (i, 0, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
  }

  FOR (i, 0, n) {
    if (!vis[i]) {
      get_ts(i);
    }
  }

  count_paths();
  calc_values();

  cin >> E;

  k = (int)ceil(sqrt(m));

  FOR (i, 0, E) {
    char ch;
    cin >> ch;
    if (ch == 'Q') {
      int x;
      cin >> x;
      x--;
      q++;
      int val = a[x];
      FOR (j, 0, sz_updates) {
        if (c[x][updates[j]] == 0) continue;
        val += 1ll * (nb[updates[j]] - b[updates[j]] + MOD) * c[x][updates[j]] % MOD;
        if (val >= MOD) val -= MOD;
      }
      total += 1ll * val * q % MOD;
      if (total >= MOD) total -= MOD;
    }
    else {
      int x, y;
      cin >> x >> y;
      x--;
      if (sz_updates == k) {
        FOR (j, 0, sz_updates) {
          b[updates[j]] = nb[updates[j]];
        }
        sz_updates = 0;
        cnt_updates++;
        calc_values();
      }
      nb[x] = y;
      if (updating[x] != cnt_updates) {
        updates[sz_updates] = x;
        sz_updates++;
        updating[x] = cnt_updates;
      }
    }
  }

  cout << total << ENDL;
  
  return 0;
}