#include <bits/stdc++.h>
using namespace std;
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
 
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  map<int, int> idx;
  int l = 0, ans = 0;
  for (int r = 0; r < n; r++) {
    while (idx.count(a[r]) && l <= idx[a[r]]) {
      l++;
    }
    idx[a[r]] = r;
    ans = max(ans, r - l + 1);
  }

  cout << ans << '\n';
}