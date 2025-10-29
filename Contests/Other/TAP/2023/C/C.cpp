#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for (int i = (int)b - 1; i >= (int)a; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main() { __
  int n;
  cin >> n;
  int a[n], b[n];
  FOR (i, 0, n) {
    cin >> a[i];
  }
  FOR (i, 0, n) {
    cin >> b[i];
  }

  sort(a, a + n);
  sort(b, b + n);

  int mn = 2e9, mx = 0;
  FOR (i, 0, n) {
    mn = min(mn, a[i] + b[n - 1 - i]);
    mx = max(mx, a[i] + b[n - 1 - i]);
  }
  cout << mx - mn << ENDL;

  return 0;
}