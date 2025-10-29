#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/**
 * Descripcion: Algoritmo rapido para maximo emparejamiento bipartito.
 * el grafo g debe de ser una lista de los vecinos de la particion
 * izquierda y m el numero de nodos en la particion derecha.
 * Retorna (Numero de emparejamientos, btoa[]) donde btoa[i] sera el
 * emparejamiento para el vertice i del lado derecho o -1 si no lo tiene
 * Tiempo: O(sqrt(V)E)
 */
pair<int, vi> hopcroftKarp(vector<vi>& g, int m) {
  int res = 0;
  vi btoa(m, -1), A(SZ(g)), B(m), cur, next;
  auto dfs = [&](auto self, int a, int L) -> bool {
    if (A[a] != L) return 0;
    A[a] = -1;
    for (int b : g[a]) if (B[b] == L + 1) {
      B[b] = 0;
      if (btoa[b] == -1 || self(self, btoa[b], L + 1)) return btoa[b] = a, 1;
    }
    return 0;
  };
  while (1) {
    fill(ALL(A), 0);
    fill(ALL(B), 0);
    /// Encuentra los nodos restantes para BFS (i.e. con layer 0)
    cur.clear();
    for (int a : btoa) if(a != -1) A[a] = -1;
    FOR (a, 0, SZ(g)) if(A[a] == 0) cur.pb(a);
    /// Encuentra todas las layers usando BFS
    for (int lay = 1;; lay++) {
      bool islast = 0;
      next.clear();
      for (int a : cur) for (int b : g[a]) {
        if (btoa[b] == -1) {
          B[b] = lay;
          islast = 1;
        }
        else if (btoa[b] != a && !B[b]) {
          B[b] = lay;
          next.pb(btoa[b]);
        }
      }
      if (islast) break;
      if (next.empty()) return {res, btoa};
      for (int a : next) A[a] = lay;
      cur.swap(next);
    }
    /// Usa DFS para escanear caminos aumentantes
    FOR (a, 0, SZ(g)) res += dfs(dfs, a, 0);
  }
}

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

void solve(int n, int m) {
  vector<string> mat(n);
  FOR (i, 0, n) {
    cin >> mat[i];
  }

  vector<vi> color(n, vi(m, -1));
  color[0][0] = 0;
  auto dfs = [&](auto self, int i, int j) -> void {
    FOR (k, 0, 4) {
      int y = i + dy[k], x = j + dx[k];
      if (y < 0 || y >= n || x < 0 || x >= m || color[y][x] != -1)
        continue;
      color[y][x] = color[i][j] ^ 1;
      self(self, y, x);
    }
  };

  dfs(dfs, 0, 0);

  auto id = [&](int i, int j) -> int {
    return i * m + j;
  };

  vector<vi> g(n * m, vi());

  FOR (i, 0, n) {
    FOR (j, 0, m) {
      if (mat[i][j] == '#' || color[i][j] == 1)
        continue;
      FOR (k, 0, 4) {
        int y = i + dy[k], x = j + dx[k];
        if (y < 0 || y >= n || x < 0 || x >= m || mat[y][x] == '#')
          continue;
        g[id(i, j)].pb(id(y, x));
      }
    }
  }

  int mxMatching = hopcroftKarp(g, n * m).first;

  auto getMatching = [&](int bannedI, int bannedJ) -> int {
    vi erased;
    FOR (i, 0, n) {
      FOR (j, 0, m) {
        if (mat[i][j] == '#' || color[i][j] == 1)
          continue;
        auto it = find(ALL(g[id(i, j)]), id(bannedI, bannedJ));
        if (it != g[id(i, j)].end()) {
          erased.pb(id(i, j));
          g[id(i, j)].erase(it);
        }
      }
    }
    vi erasedFromBanned = g[id(bannedI, bannedJ)];
    g[id(bannedI, bannedJ)].clear();
    int matching = hopcroftKarp(g, n * m).first;
    for (auto &x : erased)
      g[x].pb(id(bannedI, bannedJ));
    g[id(bannedI, bannedJ)] = erasedFromBanned;
    return matching;
  };

  int ans = 0;

  FOR (bannedI, 0, n) {
    FOR (bannedJ, 0, m) {
      if (mat[bannedI][bannedJ] == '#')
        continue;
      int matching = getMatching(bannedI, bannedJ);
      if (matching == mxMatching)
        ans++;
    }
  }

  cout << ans << ENDL;
  
}

signed main() { __
  int n, m;
  while (cin >> n >> m) {
    solve(n, m);
  }
  return 0;
}