#include <bits/stdc++.h>
using namespace std;

int go(vector<vector<int>>& g, bool odd) {
  int n = int(g.size()), t = 1;
  queue<int> q;
  vector<int> time(n, -1);
  for (int i = odd; i < n; i += 2) {
    if (time[i] == -1) {
      time[i] = t;
      q.push(i);
    }
    stack<int> st;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto v : g[u]) {
        if (time[v] == -1) {
          time[v] = time[u] + 1;
          st.push(v);
        }
      }
    }
    while (!st.empty()) {
      q.push(st.top());
      st.pop();
    }
    t++;
  }
  bool impossible = count(time.begin(), time.end(), -1) > 0;
  return impossible ? int(1e9) : *max_element(time.begin(), time.end());
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int ans = min(go(g, 0), go(g, 1));
  if (ans == int(1e9)) {
    ans = -1;
  }

  cout << ans << '\n';
}