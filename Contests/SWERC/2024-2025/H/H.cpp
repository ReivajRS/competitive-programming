#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  map<string ,int> cnt;
  string mx;
  for (int i = 0; i < n; ++i) {
    string name;
    cin >> name;
    cnt[name]++;
    mx = name;
  }

  for (auto [name, c] : cnt) {
    if (c > cnt[mx]) {
      mx = name;
    }
  }
  cout << mx << '\n';

  return 0;
}