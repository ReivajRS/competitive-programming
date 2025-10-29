#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> prefix(n + 1);
  vector<queue<int>> v(10);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    prefix[i + 1] = (prefix[i] + a[i]) % 10;
    v[prefix[i]].push(i);
  }
  v[prefix[n]].push(n);

  for (int i = 0; i < n; i++) {
    int l = prefix[i];
    while (!v[l].empty() && v[l].front() <= i) v[l].pop();
    if (v[l].empty()) {
      cout << -1 << ' ';
      continue;
    }
    cout << v[l].front() - i << ' ';
  }
  cout << '\n';

  return 0;
}