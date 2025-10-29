#include <bits/stdc++.h>
using namespace std;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  constexpr int maxn = 20001;
  vector<int> dist(maxn, -1);
  dist[n] = 0;
  queue<int> q;
  q.push(n);

  while (!q.empty()) {
    int x = q.front();
    q.pop();
    if (x - 1 >= 0 && dist[x - 1] == -1) {
      dist[x - 1] = dist[x] + 1;
      q.push(x - 1);
    }
    if (x * 2 < maxn && dist[x * 2] == -1) {
      dist[x * 2] = dist[x] + 1;
      q.push(x * 2);
    }
  }

  cout << dist[m] << '\n';
  
  return 0;
}