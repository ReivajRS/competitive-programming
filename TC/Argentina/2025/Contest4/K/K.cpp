#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n;
  cin >> n;

  vector<int> minTimes;
  for (int i = 0; i < n; ++i) {
    string _;
    int a, b, c;
    cin >> _ >> a >> b >> c;
    vector<int> times;
    if (a != -1) {
      times.push_back(a);
    }
    if (b != -1) {
      times.push_back(b);
    }
    if (c != -1) {
      times.push_back(c);
    }
    if (!times.empty()) {
      minTimes.push_back(*min_element(times.begin(), times.end()));
    }
  }
  sort(minTimes.begin(), minTimes.end());

  int t = 300;
  for (int i = 0; i < minTimes.size(); ++i) {
    if (t < minTimes[i]) {
      cout << i << '\n';
      return 0;
    }
    t -= minTimes[i];
  }
  cout << minTimes.size() << '\n';
  
  return 0;
}