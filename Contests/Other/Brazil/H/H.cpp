#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, k;
  cin >> n >> k;

  vector<int> a(n), c(n);
  vector<vector<int>> ofColor(k);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> c[i];
    --a[i], --c[i];
    ofColor[c[i]].push_back(a[i]);
  }

  for (int i = 0; i < k; ++i) {
    sort(rbegin(ofColor[i]), rend(ofColor[i]));
  }

  vector<int> res;
  for (int x : c) {
    res.push_back(ofColor[x].back());
    ofColor[x].pop_back();
  }

  cout << (is_sorted(begin(res), end(res)) ? "Y" :"N") << '\n';

  return 0;
}