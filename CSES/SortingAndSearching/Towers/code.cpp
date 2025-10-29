#include <bits/stdc++.h>
using namespace std;
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
 
  int n;
  cin >> n;

  multiset<int> towers;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    auto it = towers.upper_bound(x);
    if (it != towers.end()) {
      towers.erase(it);
    }
    towers.insert(x);
  }

  cout << int(towers.size()) << '\n';
}