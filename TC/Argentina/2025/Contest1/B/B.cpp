#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

//<>

int ask(int a, int b) {
  cout << "? " << a << ' ' << b << endl;
  int ret;
  cin >> ret;
  if (ret == -1) exit(0);
  return ret;
}

void solve() {
  int n;
  cin >> n;

  vector<int> p(n);
  int i = 2;
  while (i < n && ask(i, 1)) {
    ++i;
  }
  p[i] = 1;
  int j = 2;
  while (++i < n) {
    while (j != i - 1 && ask(i, j)) {
      ++j;
    }
    p[i] = j++;
  }

  cout << "!";
  for (int i = 1; i < n; ++i) {
    cout << ' ' << p[i];
  }
  cout << endl;
}

signed main() {
  // cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}