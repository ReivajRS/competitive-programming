#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = a - 1; i >= b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main() { __
  string s;
  int n, m;
  cin >> s >> m;

  n = SZ(s);

  vi a(n + 1, 0), t(n + 1, 0), g(n + 1, 0), c(n + 1, 0);

  FOR(i, 1, n + 1) {
    if (s[i - 1] == 'A')
      a[i]++;
    if (s[i - 1] == 'T')
      t[i]++;
    if (s[i - 1] == 'G')
      g[i]++;
    if (s[i - 1] == 'C')
      c[i]++;
    a[i] += a[i - 1];
    t[i] += t[i - 1];
    g[i] += g[i - 1];
    c[i] += c[i - 1];
  }

  while (m--) {
    int l, r;
    vector<tuple<int, int, char>> v(4);
    cin >> l >> r;
    v[0] = {-(a[r] - a[l - 1]), 0, 'A'};
    v[1] = {-(t[r] - t[l - 1]), 1, 'T'};
    v[2] = {-(g[r] - g[l - 1]), 2, 'G'};
    v[3] = {-(c[r] - c[l - 1]), 3, 'C'};
    sort(v.begin(), v.end());
    for (auto &p : v)
      cout << get<2>(p);
    cout << ENDL;
  }

  return 0;
}