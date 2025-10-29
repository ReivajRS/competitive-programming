#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n, m;

  vector<pi> a;

  cin >> n;
  // vi a(n);
  FOR (i, 0, n) {
    int x;
    cin >> x;
    a.pb({x, 1});
  }

  cin >> m;
  FOR (i, 0, m) {
    int x;
    cin >> x;
    a.pb({x, 2});
  }

  sort(ALL(a));

  int sum1 = n * 3, sum2 = m * 3;

  tuple<int, int, int> ans = {sum1 - sum2, sum1, sum2};

  FOR (i, 0, n + m) {
    if (a[i].second == 1) {
      sum1--;
    }
    else {
      sum2--;
    }
    ans = max(ans, {sum1 - sum2, sum1, sum2});
  }

  auto [_, x, y] = ans;

  cout << x << ':' << y << ENDL;
  
  return 0;
}