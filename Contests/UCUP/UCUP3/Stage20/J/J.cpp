#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int cnt = 0;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    if (a[i] != i) {
      cnt++;
    }
  }

  if (n == 2) {
    cout << "Alice" << '\n';
    return;
  }

  if (cnt == 2 && s[0] == 'A') {
    cout << "Alice" << '\n';
    return;
  }

  if (cnt == 3 && n == 3) {
    cout << (s[0] == 'A' ? "Bob" : "Alice") << '\n';
    return;
  }

  cout << "Bob" << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }
}