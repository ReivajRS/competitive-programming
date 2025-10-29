#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'

void solve() {
  int n, k, m;
  cin >> n >> k >> m;

  string s, s2 = "";
  cin >> s;

  int msk = 0;

  for (char c : s) {
    msk |= (1 << (c - 'a'));
    if (msk == (1 << k) - 1) {
      s2 += c;
      msk = 0;
    }
    if (SZ(s2) == n) {
      cout << "YES" << ENDL;
      return;
    }
  }

  cout << "NO" << ENDL;
  FOR (i, 0, k) {
    if (!(msk & (1 << i))) {
      while (SZ(s2) < n)
        s2 += i + 'a';
      cout << s2 << ENDL;
      return;
    }
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  cin >> tc;
  while(tc--) {
    solve();
  }

  return 0;
}