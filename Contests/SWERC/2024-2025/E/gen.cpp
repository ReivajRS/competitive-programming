#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int random(int l, int r) {
  return uniform_int_distribution<int>(l, r)(rng);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n = random(3, 10);
  cout << n << '\n';
  for (int i = 0; i < n; ++i) {
    int x = random(1, 20), y = random(1, 20);
    cout << x << ' ' << y << '\n';
  }

  return 0;
}