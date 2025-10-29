#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  multiset<int> h;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    h.insert(x);
  }
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;

    auto it = h.lower_bound(x);
    if (*it == x) {
      cout << *it << '\n';
      h.erase(it);
      continue;
    }
    
    if (it == h.begin()) {
      cout << -1 << '\n';
      continue;
    }
    
    it--;
    if (*it > x) {
      cout << -1 << '\n';
    }
    else {
      cout << *it << '\n';
      h.erase(it);
    }
  }
}