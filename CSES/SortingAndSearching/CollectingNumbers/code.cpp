#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<int> a(n), p(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    p[a[i]] = i;
  }

  int ans = 0, last = n;
  for (int i = 0; i < n; i++) {
    if (p[i] < last) {
      ans++;
    }
    last = p[i];
  }

  cout << ans << '\n';
}