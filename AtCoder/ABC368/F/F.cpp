#include <bits/stdc++.h>
using namespace std;

signed main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (auto &x : a) {
    cin >> x;
  }

  constexpr int maxn = 100001;
  vector<int> g(maxn);

  for (int i = 1; i < maxn; i++) {
    for (int j = i * 2; j < maxn; j += i) {
      g[j] += (g[i] == g[j]);
    }
  }

  int nsum = 0;
  for (auto &x : a) {
    nsum ^= g[x];
  }

  cout << (nsum != 0 ? "Anna" : "Bruno") << '\n';
}