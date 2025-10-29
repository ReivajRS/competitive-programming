#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) (int(x.size()))
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

vector<string> split(string s) {
  stringstream ss(s);
  vector<string> ret;
  while (ss.good()) {
    string t;
    ss >> t;
    ret.push_back(t);
  }
  return ret;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> m >> n;

  string xd;
  getline(cin, xd);

  queue<int> q;
  vector<bool> vis(2 * n);
  vector<vector<int>> g(2 * n);
  vector<int> deg(m), con(m);
  for (int i = 0; i < m; ++i) {
    string line;
    getline(cin, line);
    vector<string> v = split(line);

    auto getID = [n](string s) {
      int id;  
      bool neg = false;
      if (s[0] == '!') {
        neg = true;
        id = stoi(s.substr(1));
      } else {
        id = stoi(s);
      }
      id--;
      return !neg ? id : n + id;
    };

    if (v.size() == 1) {
      int id = getID(v[0]);
      vis[id] = true;
      q.push(id);
      continue;
    }

    deg[i] = int(v.size()) - 2;
    con[i] = getID(v.back());
    for (int j = 0; v[j][0] != '-'; ++j) {
      g[getID(v[j])].push_back(i);
    }
  }

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int i : g[u]) {
      if (!--deg[i] && !vis[con[i]]) {
        vis[con[i]] = true;
        q.push(con[i]);
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    if (vis[i] && vis[i + n]) {
      cout << "conflict\n";
      return 0;
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << "FT"[vis[i]];
  }
  cout << '\n';

  return 0;
}