#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

//<>

void solve() {
  int n, q;
  cin >> n >> q;

  vector<vector<int>> nxt(30, vector<int>(n, -1));
  vector<int> w(n);
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
    for (int j = 29; j >= 0; --j) {
      if (w[i] >> j & 1) {
        nxt[j][i] = i;
      } else {
        if (i) {
          nxt[j][i] = nxt[j][i - 1];
        }
        if (j != 29) {
          nxt[j][i] = max(nxt[j][i], nxt[j + 1][i]);
        }
      }
    } 
  }
  vector<int> sufXor(n + 1);
  for (int i = n - 1; i >= 0; --i) {
    sufXor[i] = sufXor[i + 1] xor w[i];
  }

  while (q--) {
    int x;
    cin >> x;

    int i = n - 1;
    for (int b = 29; b >= 0 && i >= 0; --b) {
      if (!(x >> b & 1)) {
        continue;
      }
      int j = nxt[b][i];
      x = x xor sufXor[j + 1] xor sufXor[i + 1];
      i = j;
      if (i == -1) {
        break;
      }
      if (x < w[i]) {
        break;
      }
      x = x xor w[i];
      --i;
    }
    cout << n - i - 1 << ' ';
  }
  cout << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}