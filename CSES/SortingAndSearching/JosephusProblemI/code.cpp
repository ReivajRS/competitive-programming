#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  list<int> l;
  for (int i = 0; i < n; i++) {
    l.push_back(i + 1);
  }

  auto it = l.begin();

  while (!l.empty()) {
    it++;
    if (it == l.end()) {
      it = l.begin();
    }
    cout << *it << ' ';
    it = l.erase(it);
    if (it == l.end()) {
      it = l.begin();
    }
  }

  cout << '\n';
}