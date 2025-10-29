#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)

constexpr int N = 100005;

vector<int> cX(N), cY(N), cZ(N);

void solve() {
  int n;
  cin >> n;

  vector<int> x(n), y(n), z(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i] >> z[i];
    ++cX[x[i]], ++cY[y[i]], ++cZ[z[i]];
  }

  auto density = [&](int i) {
    return max({cX[x[i]], cY[y[i]], cZ[z[i]]}) - 1;
  };

  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return density(i) > density(j);
  });

  for (int i = 0; i < n; ++i) {
    while (!order.empty() && density(order.back()) < i) {
      order.pop_back();
    }
    cout << n - order.size() << " \n"[i == n - 1];
  }

  for (int i = 0; i < n; ++i) {
    --cX[x[i]], --cY[y[i]], --cZ[z[i]];
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int t;
  cin >> t;

  while (t--) {
    solve();
  }
}