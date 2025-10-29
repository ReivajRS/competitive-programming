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

const int N = 550, MAXN = N * N;
string mat[N];
vi g[MAXN];
unordered_set<int> gr[MAXN];
int vis[MAXN], id[N][N], parent[MAXN], supernode[MAXN];
bool in_deg[MAXN];
unordered_map<int, unordered_set<int>> mp_supernode;
int n, m, num_comps = 0, ans = 0;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int encode(int i, int j) { return i * m + j; }

pi decode(int x) { return {x / m, x % m}; }

bool is_valid(int i, int j) {
  return i >= 0 && i < n && j >= 0 && j < m;
}

pi get_dif(char c) {
  if (c == '>') return {0, 1};
  if (c == '<') return {0, -1};
  if (c == '^') return {-1, 0};
  return {1, 0};
}

vi scc() {
  int t = 0, ncomps = 0;
  vi tin(MAXN), scc(MAXN, -1), z;
  auto dfs = [&](auto&& self, int u) -> int {
    int low = tin[u] = ++t, x; z.push_back(u);
    for (auto v : g[u]) if (scc[v] < 0)
      low = min(low, tin[v] ?: self(self, v));
    if (low == tin[u]) {
      do {
        x = z.back(); z.pop_back();
        scc[x] = ncomps;
      } while (x != u);
      ncomps++;
    }
    return tin[u] = low;
  };
  FOR (i, 0, MAXN) if (scc[i] == -1) dfs(dfs, i);
  num_comps = ncomps;
  return scc;
}

unordered_map<int, int> mp_vis;

void dfs(int u) {
  auto [i, j] = decode(u);
  vi inserted;
  if (mp_supernode.count(u)) {
    for (auto &v : mp_supernode[u]) {
      mp_vis[v]++;
      inserted.pb(v);
    }
  }
  else {
    FOR (k, 0, 4) {
      int ii = i + dy[k], jj = j + dx[k];
      if (is_valid(ii, jj) && mat[ii][jj] == '#') {
        mp_vis[id[ii][jj]]++;
        inserted.pb(id[ii][jj]);
      }
    }
  }
  for (auto &v : gr[u]) {
    dfs(v);
  }
  ans = max(ans, SZ(mp_vis));
  for (auto &v : inserted) {
    mp_vis[v]--;
    if (mp_vis[v] == 0) {
      mp_vis.erase(v);
    }
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  cin >> n >> m;

  FOR (i, 0, n) {
    cin >> mat[i];
  }

  FOR (i, 0, n) {
    FOR (j, 0, m) {
      id[i][j] = encode(i, j);
    }
  }

  FOR (i, 0, n) {
    FOR (j, 0, m) {
      if (mat[i][j] == '.' || mat[i][j] == '#') {
        continue;
      }
      auto [di, dj] = get_dif(mat[i][j]);
      int ii = i + di, jj = j + dj;
      if (is_valid(ii, jj) && mat[ii][jj] != '.' && mat[ii][jj] != '#') {
        g[id[i][j]].pb(id[ii][jj]);
      }   
    }
  }

  vi comp = scc();
  vector<vi> comps(num_comps + 1);

  FOR (u, 0, n * m) {
    comps[comp[u]].pb(u);
  }

  fill(supernode, supernode + MAXN, -1);
  int supernode_cnt = 0;

  FOR (i, 0, SZ(comps)) {
    if (SZ(comps[i]) > 1) {
      for (auto &v : comps[i]) {
        auto [ii, jj] = decode(v);
        supernode[v] = n * m + supernode_cnt;
        FOR (k, 0, 4) {
          int iii = ii + dy[k], jjj = jj + dx[k];
          if (is_valid(iii, jjj) && mat[iii][jjj] == '#') {
            mp_supernode[supernode[v]].insert(id[iii][jjj]);
          }
        }
      }
      supernode_cnt++;
    }
  }

  FOR (u, 0, n * m) {
    bool u_in_supernode = (supernode[u] != -1);
    auto [i, j] = decode(u);
    if (mat[i][j] == '.' || mat[i][j] == '#' || in_deg[u]) {
      in_deg[u] = 1;
      continue;
    }
    for (auto &v : g[u]) {
      auto [ii, jj] = decode(v);
      if (mat[ii][jj] == '.' || mat[ii][jj] == '#' || in_deg[u]) {
        in_deg[v] = 1;
        continue;
      }
      bool v_in_supernode = (supernode[v] != -1);
      if (u_in_supernode && v_in_supernode) {
        in_deg[u] = 1;
        in_deg[v] = 1;
        continue;
      }
      if (!u_in_supernode && v_in_supernode) {
        gr[supernode[v]].insert(u);
        in_deg[u] = 1;
        continue;
      }
      if (!u_in_supernode && !v_in_supernode) {
        gr[v].insert(u);
        in_deg[u] = 1;
        continue;
      }
    }
  }

  FOR (u, 0, n * m) {
    if (in_deg[u] == 1) {
      continue;
    }
    dfs(u);
  }

  FOR (u, n * m, n * m + supernode_cnt) {
    dfs(u);
  }

  cout << ans << ENDL;
  
  return 0;
}