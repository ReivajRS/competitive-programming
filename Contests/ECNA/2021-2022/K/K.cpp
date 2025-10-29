#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) begin(x),end(x)
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i,a,b) for(int i = (int)a - 1; i>= (int)b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

int n, m;

vi bfs(int x, vector<set<int>>& g) {
  if (x == -1) {
    return vi(SZ(g), 0);
  }

  vi d(SZ(g), 1e8);
  d[x] = 0;
  queue<int> q;
  q.push(x);
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (auto &v : g[u]) {
      if (d[u] + 1 < d[v]) {
        d[v] = d[u] + 1;
        q.push(v);
      }
    }
  }
  return d;
}

signed main() { __
  cin >> n >> m;

  set<int> s;
  s.insert(0);
  vector<vi> a(n, vi(m));
  FOR (i, 0, n) {
    FOR (j, 0, m) {
      cin >> a[i][j];
      s.insert(a[i][j]);
    }
  }

  vector<set<int>> g(SZ(s));
  vector<set<int>> gr(SZ(s));
  FOR (i, 0, n - 1) {
    FOR (j, 0, m) {
      if (a[i][j] != a[i + 1][j]) {
        g[a[i][j]].insert(a[i + 1][j]);
        gr[a[i + 1][j]].insert(a[i][j]);
      }
    }
  }

  FOR (j, 0, m) {
    g[a[n - 1][j]].insert(0);
    gr[0].insert(a[n - 1][j]);
  }

  int uno = -1, dos = -1;
  FOR (j, 0, m) {
    if (uno == -1 || a[0][j] == uno) {
      uno = a[0][j];
    } else {
      dos = a[0][j]; 
    }
  }

  // XXXXG
  // (n * 2)!

  vi duno = bfs(uno, g), ddos = bfs(dos, g), dabajo = bfs(0, gr);
  if(dos == -1){
    cout << dabajo[uno] << ENDL;
    return 0;
  }
  int ans = 1e9;
  FOR (i, 0, SZ(g)) {
    int dist = duno[i] + ddos[i] + dabajo[i];
    ans = min(ans, dist);
  }
  cout << ans << ENDL;

  return 0;
}