#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t, d, m;
  cin >> t >> d >> m;

  vector<int> a;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  a.push_back(0);
  a.push_back(d);

  sort(a.begin(), a.end());

  for (int i = 0; i < SZ(a) - 1; i++) {
    if (a[i + 1] - a[i] >= t) {
      cout << "Y" << '\n';
      return 0;
    }
  }

  cout << "N" << '\n';

  return 0;
}