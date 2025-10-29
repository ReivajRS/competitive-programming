#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  long long ans = 0;
  map<int, int> idx;
  int l = 0;

  for (int r = 0; r < n; r++) {
    int x;
    cin >> x;
    while (idx.count(x) && l <= idx[x]) {
      l++;
    }
    idx[x] = r;
    ans += r - l + 1;
  }
  
  cout << ans << '\n';
}