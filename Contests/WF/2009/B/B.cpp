#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

vector<int> getTo

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int N, G, U;
  while (cin >> N >> G >> U && N) {
    string t(N + G, '0');
    vector<vector<int>> adj(N + G), adjT(N + G);
    for (int i = 0; i < G; ++i) {
      cin >> t[i];
      string line;
      getline(cin, line);
      stringstream ss(line);
      while (ss.good()) {
        string g;
        cin >> g;
        int id = stoi(g.substr(1)) - 1;
        if (g[0] == 'g') {
          id += N;
        }
        adj[id].push_back(i), adjT[i].push_back(id);
      }
    }
  }

  return 0;
}