#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int len, n;
  cin >> len >> n;

  set<pair<int, int>> intervals = {{0, len}};
  multiset<int> lens = {len};

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    auto it = intervals.upper_bound({x, 0});
    it--;
    lens.extract(it->second - it->first);
    intervals.insert({it->first, x});
    intervals.insert({x, it->second});
    lens.insert(x - it->first);
    lens.insert(it->second - x);
    intervals.erase(it);
    cout << *lens.rbegin() << ' ';
  }

  cout << '\n';
}