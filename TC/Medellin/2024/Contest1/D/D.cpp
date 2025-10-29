#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vi a(n);
  FOR (i, 0, n) {
    cin >> a[i];
  }

  int mx = 0;
  int sum = 0;

  FOR (i, 0, n) {
    mx = max(mx, a[i]);
  }

  FOR (i, 0, n) {
    sum += mx - a[i];
  }

  cout << sum << ENDL;

  return 0;
}