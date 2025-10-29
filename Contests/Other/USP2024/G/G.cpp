#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

constexpr ll INF = 1e18;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<int> a(n + 1);
  a[0] = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  vector<ll> prev(n, INF), curr(n, INF);
  prev[0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i + (!i); ++j) {
      curr[i] = min(curr[i], prev[j] + abs(a[j] - a[i + 1]));
      curr[j] = min(curr[j], prev[j] + abs(a[i] - a[i + 1]));
    }
    curr.swap(prev);
    fill(curr.begin(), curr.end(), INF);
  }
  cout << *min_element(prev.begin(), prev.end()) << '\n';

  return 0;
}