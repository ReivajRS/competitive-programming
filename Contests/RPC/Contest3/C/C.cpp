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
#define FOR(i, a, b) for (int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0);

signed main() { __
  int n, k, x, y;
  cin >> n >> k;
  cin >> x >> y;

  double sum = n * x;
  sum -= k * y;

  cout << setprecision(10) << fixed;
  double ans = sum / (n - k);
  if (ans < 0 || ans > 100)
    cout << "impossible" << ENDL;
  else
    cout << sum / (n - k);

  return 0;
}