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
    cin >> a[i].first >> a[i].second;
  }

  sort(ALL(a));

  int last = 0;

  for (auto &p : a) {
    if (p.second >= last) {
      last = p.second;
    } else {
      last = p.first;
    }
  }

  cout << last << ENDL;

  return 0;
}