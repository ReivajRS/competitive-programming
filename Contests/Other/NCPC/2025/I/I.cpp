#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int N, M;
  cin >> N >> M;

  vector<set<int>> adj(N);
  while (M--) {
    int u, v;
    cin >> u >> v;
    adj[u-1].insert(v-1);
  }

  vector<int> CC(N);
  for (int i = 0; i < N; ++i) {
    for (int j : adj[i]) {
      if (!adj[j].count(i)) {
        ++CC[j];
      }
    }
  }

  auto itMax = max_element(CC.begin(), CC.end());
  cout << itMax - CC.begin() + 1 << ' ' << *itMax << '\n';
}
