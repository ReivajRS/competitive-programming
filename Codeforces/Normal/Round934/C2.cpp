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
  vi a(n), c;
  map<int, int> m;

  for (auto &x : a) {
    cin >> x;
    m[x]++;
  }
  sort(ALL(a));

  int cnt = 0;

  FOR (i, 0, n) {
    if (i && a[i - 1] != a[i])
      cnt++;
    if (m[a[i]] <= cnt) {
      cout << a[i] << ENDL;
    }
  }

  return 0;
}