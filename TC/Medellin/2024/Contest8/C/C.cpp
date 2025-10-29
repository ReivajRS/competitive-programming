#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<ll> a(n + 2);
  FOR (i, 1, n + 1) {
    cin >> a[i];
  }
  a[n + 1] = m;

  vector<vector<ll>> p(2, vector<ll>(n + 5));
  ROF (i, SZ(a) - 1, 0) {
    p[0][i] = p[1][i + 1];
    p[1][i] = p[0][i + 1];
    p[1][i] += (a[i + 1] - a[i]);
  }

  ll ans = p[1][0];
  FOR (i, 0, SZ(a) - 1) {
    if (a[i] + 2 > a[i + 1]) {
      continue;
    }
    ll k = (i & 1) ^ 1;
    ll suma = p[1][0] - p[k][i];
    ans = max(ans, suma + p[k][i + 1] + a[i + 1] - a[i] - 1);
  }
  cout << ans << ENDL;

  return 0;
}