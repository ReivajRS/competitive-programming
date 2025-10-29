#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, a, b;
  cin >> n >> a >> b;

  if (a + b > n || (a > 0 && b == 0) || (b > 0 && a == 0)) {
    cout << "NO" << '\n';
    return;
  }
  
  vector<int> ca(n), cb(n);
  for (int i = 0; i < n; i++) {
    ca[i] = n - i;
  }

  int card = n;

  for (int i = 0; i < n - a - b; i++) {
    cb[i] = card--;
  }
  for (int i = n - b; i < n; i++) {
    cb[i] = card--;
  }
  for (int i = n - a - b; i < n - b; i++) {
    cb[i] = card--;
  }

  cout << "YES" << '\n';
  for (auto x : ca) {
    cout << x << ' ';
  }
  cout << '\n';
  for (auto x : cb) {
    cout << x << ' ';
  }
  cout << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }
}