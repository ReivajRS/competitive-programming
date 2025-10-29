#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())

const int maxn = 10001;
int a[maxn];

void solve() {
  int n;
  cin >> n;
  cout << a[n] << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  a[0] = 0;
  a[1] = 1;
  a[2] = 2;
  a[3] = 2;
  a[4] = 2;

  int ones = 4, cnt = 2;
  for (int i = 5; i < maxn; i++) {
    if (i == ones * 2 + 2) {
      ones = i;
      cnt++;
    }
    a[i] = cnt;
    if (ones < i) a[i]++;
    cout << i << ' ' << a[i] << '\n';
  }

  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }

  return 0;
}