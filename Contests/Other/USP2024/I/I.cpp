#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  int mx = 0;
  bool odd = false;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    mx = max(mx, x);
    odd |= x & 1;
  }

  if (mx == 1 || !odd) {
    cout << "1\n";
  } else {
    cout << "2\n";
  }

  return 0;
}