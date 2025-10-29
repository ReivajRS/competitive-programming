#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, int source, int auxilary, int destination) {
  if (n == 1) {
    cout << source << ' ' << destination << '\n';
    return;
  }
  hanoi(n - 1, source, destination, auxilary);
  cout << source << ' ' << destination << '\n';
  hanoi(n - 1, auxilary, source, destination);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  cout << ((1 << n) - 1) << '\n';
  hanoi(n, 1, 2, 3);
  
  return 0;
}