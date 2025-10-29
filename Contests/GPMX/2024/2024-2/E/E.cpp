#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main() { __
  int n;
  cin >> n;
  
  vector<pi> a(n);
  FOR (i, 0, n) {
    int x;
    cin >> x;
    a[i] = {x - 1, i};
  }

  sort(ALL(a));
  vi ava;
  vector<pi> edges;

  FOR (i, 0, n) {
    if (SZ(ava) < a[i].first) {
      cout << -1 << ENDL;
      return 0;
    }
    FOR (j, 0, SZ(ava)) {
      if (a[i].first == 0)
        break;
      a[i].first--;
      edges.pb({a[i].second + 1, ava[j] + 1});
    }
    ava.pb(a[i].second);
  }

  cout << SZ(edges) << ENDL;

  for (auto &[x, y] : edges) {
    cout << x << ' ' << y << ENDL;
  }

  return 0;
}