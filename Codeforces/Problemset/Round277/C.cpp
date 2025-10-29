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
  int n, p;
  cin >> n >> p;
  string s;
  cin >> s;

  p--;

  vi m(n);
  vector<bool> a(n, 0);
  int x = 0;

  FOR (i, 0, n) {
    m[i] = n - 1 - i;
    if (s[i] != s[m[i]]) {
      a[i] = a[m[i]] = 1;
      x++;
    }
  }

  auto minDif = [&](int i) -> int {
    int mn = min(s[i], s[m[i]]), mx = max(s[i], s[m[i]]);
    return min(mx - mn, mn + 'z' - 'a' - mx + 1);
  };

  auto calc = [&](vector<bool> a, int x, int st, int inc) -> int {
    int cnt = 0;
    int i = st;
    bool f = 0;
    while (x > 0) {
      if (!a[i]) {
        i += inc;
        if (i == n) i = 0;
        if (i < 0) i = n - 1;
        if (x > 0 && f) cnt++;
        continue;
      }
      if (!f) cnt += abs(p - i), f = 1;
      cnt += minDif(i);
      a[i] = a[m[i]] = 0;
      x -= 2;
      if (x > 0) cnt++;
      i += inc;
      if (i == n) i = 0;
      if (i < 0) i = n - 1;
    }
    return cnt;
  };

  cout << min({calc(a, x, (n - 1) / 2, -1), calc(a, x, n / 2, 1), calc(a, x, 0, 1), calc(a, x, n - 1, -1)}) << ENDL;

  return 0;
}