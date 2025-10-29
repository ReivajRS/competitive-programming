#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

const int maxn = 101 * 1001, maxlog = 20;

int n;
int deg[maxn];
vi g[maxn];

int jump[maxn][maxlog];
int depth[maxn];

void dfs(int u, int p = -1, int d = 0) {
  depth[u] = d;
  jump[u][0] = p;
  for (auto &v : g[u]) {
    if (v != p) {
      dfs(v, u, d + 1);
    }
  }
}

void build(int n, int root) {
  memset(jump, -1, sizeof jump);

  dfs(root);

  for (int i = 1; i < maxlog; i++) {
    for (int u = 0; u < n; u++) {
      if (jump[u][i - 1] != -1) {
        jump[u][i] = jump[jump[u][i - 1]][i - 1];
      }
    }
  }
}

int LCA(int p, int q) {
  if (depth[p] < depth[q]) {
    swap(p, q);
  }

  int dist = depth[p] - depth[q];
  for (int i = maxlog - 1; i >= 0; i--) {
    if ((dist >> i) & 1) {
      p = jump[p][i];
    }
  }

  if (p == q) {
    return p;
  }

  for (int i = maxlog - 1; i >= 0; i--) {
    if (jump[p][i] != jump[q][i]) {
      p = jump[p][i];
      q = jump[q][i];
    }
  }
  
  return jump[p][0];
}

int dist(int u, int v, int lca) {
  return depth[u] + depth[v] - 2 * depth[lca];
}

string nth(int n) {
  int x = n % 10;
  int y = n / 10;
  y %= 10;
  if (x == 1 && y != 1) {
    return to_string(n) + "st";
  }
  if (x == 2 && y != 1) {
    return to_string(n) + "nd";
  }
  if (x == 3 && y != 1) {
    return to_string(n) + "rd";
  }
  return to_string(n) + "th";
}

void solve(int m, string sm, int n, string sn) {
  if (m == 0) {
    if (n == 1) {
      cout << sn << " is the child of " << sm << ENDL;
      return;
    }
    cout << sn << " is the ";
    FOR (i, 0, n - 2) {
      cout << "great ";
    }
    cout << "grandchild of " << sm << ENDL;
    return;
  }

  if (m == n) {
    if (m == 1) {
      cout << sm << " and " << sn << " are siblings " << ENDL;
      return;
    }
    cout << sm << " and " << sn << " are " << nth(m - 1) << " cousins " << ENDL;
    return;
  }
  int r = abs(n - m);
  cout << sm << " and " << sn << " are " << nth(m - 1) << " cousins, " << r;
  if (r == 1) {
    cout << " time removed" << ENDL;
  } else {
    cout << " times removed" << ENDL;
  }
}

signed main() { __
  int k, q;
  cin >> k >> q;

  map<string, int> names;
  
  auto process = [&](string name) -> void {
    if (!names.count(name)) {
      names[name] = SZ(names);
    }
  };
  
  FOR (i, 0, k) {
    string s;
    cin >> s;

    process(s);

    int child;
    cin >> child;
    while (child--) {
      string t;
      cin >> t;
      process(t);

      g[names[s]].pb(names[t]);
      deg[names[t]]++;
    }
  }

  n = SZ(names);

  int root;
  FOR (i, 0, n) {
    if (deg[i] == 0) {
      root = i;
      break;
    }
  }

  build(n, root);

  while (q--) {
    string s, t;
    cin >> s >> t;
    int u = names[s], v = names[t];
    int lca = LCA(u, v);
    int du = dist(u, lca, lca), dv = dist(v, lca, lca);

    if (du == 0) {
      solve(du, s, dv, t);
      continue;
    }
    if (dv == 0) {
      solve(dv, t, du, s);
      continue;
    }
    solve(min(du, dv), s, max(du, dv), t);
  }

  return 0;
}