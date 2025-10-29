#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using pi = pair<int,int>;

#define FOR(i,a,b) for(int i = (int)a;i<(int)b;i++)
#define ENDL '\n'

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<map<string, int>> mp_children;
  vector<string> name, path;
  vector<int> sz;
  vector<vector<int>> g;

  auto add = [&](string pt, string nm) -> int {
    name.push_back(nm);
    path.push_back(pt);
    sz.push_back(0);
    g.push_back(vector<int>());
    mp_children.push_back(map<string, int>());
    return (int)g.size() - 1;
  };

  add("/", "/");

  for (int _ = 0; _ < n; ++_) {
    string full_path;
    int file_sz;
    cin >> full_path >> file_sz;

    stringstream ss(full_path);
    int curr_node = 0;
    string curr_path = "/", next;
    getline(ss, next, '/');
    while (getline(ss, next, '/')) {
      curr_path += next + "/";
      if (mp_children[curr_node].find(next) == mp_children[curr_node].end()) {
        int i = add(curr_path, next);
        g[curr_node].push_back(i);
        mp_children[curr_node][next] = (int)g[curr_node].size() - 1;
      }
      curr_node = g[curr_node][mp_children[curr_node][next]];
    }
    sz[curr_node] += file_sz;
  }
  
  int t;
  cin >> t;

  int N = (int)g.size();
  for (int u = 0; u < N; ++u) {
    sort(g[u].begin(), g[u].end(), [&](int i, int j) -> bool {
      return name[i] < name[j];
    });
  }

  vector<bool> directory_children(N), expand(N);
  auto dfs_precalc = [&](auto&& dfs, int u) -> bool {
    for (int v : g[u]) {
      dfs(dfs, v);
      expand[u] = expand[u] | (sz[v] >= t);
      if (!g[v].empty()) {
        directory_children[u] = true;
      }
      sz[u] += sz[v];
    }
    return expand[u];
  };
  dfs_precalc(dfs_precalc, 0);

  auto dfs_print_ans = [&](auto &&dfs, int u) -> void {
    if (!directory_children[u]) {
      cout << "  " << path[u] << ' ' << sz[u] << '\n';
      return;
    }
    cout << "+-"[expand[u]] << ' ' << path[u] << ' ' << sz[u] << '\n';
    if (sz[u] < t || !expand[u]) {
      return;
    }
    for (int v : g[u]) {
      if (!g[v].empty()) {
        dfs(dfs, v);
      }
    }
  };
  dfs_print_ans(dfs_print_ans, 0);
}