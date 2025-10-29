#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main() { __
  int n, m;
  cin >> n >> m;

  vi a(n);
  iota(ALL(a), 1);

  while (m--) {
    char c1, c2;
    int x1, x2;
    cin >> c1 >> x1 >> c2 >> x2;

    int p1 = 0, p2 = 0;
    FOR (i, 0, n) {
      if (a[i] == x1) {
        p1 = i;
      }
      if (a[i] == x2) {
        p2 = i;
      }
    }

    if (p1 < p2) {
      continue;
    }

    FOR (i, p2, p1) {
      swap(a[i], a[i + 1]);
    }
  }

  FOR (i, 0, n) {
    cout << "T" << a[i] << " ";
  }
  cout << ENDL;

  return 0;
}