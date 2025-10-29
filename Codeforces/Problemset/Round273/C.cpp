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
  // int r, g, b;
  vi a(3);
  cin >> a[0] >> a[1] >> a[2];

  int cnt = 0;

  while (a[0] || a[1] || a[2]) {
    sort(ALL(a));

    for (auto x : a)
      cerr << x << ' ';
    cerr << ENDL;

    int x = a[2] / 2;
    if (x == 0 || (a[0] == 0 && a[1] == 0)) {
      break;
    }

    // cout << "x: " << x << ENDL;

    bool f = a[1] != 0;
    if (a[f] >= x) {
      // cerr << "op 1" << ENDL;
      cnt += x;
      a[f] -= x;
      a[2] -= x * 2;
    } else {
      // cerr << "op 2" << ENDL;
      cnt += a[f];
      a[2] -= a[f] * 2;
      a[f] = 0;
    }

    // cerr << '-' << cnt << ENDL;

  }

  if (a[0] && a[1] && a[2]) {
    cnt += *min_element(ALL(a));
  }

  cout << cnt << ENDL;

  return 0;
}