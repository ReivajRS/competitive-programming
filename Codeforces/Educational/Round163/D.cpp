#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve() {
  string s;
  cin >> s;

  for (int k = SZ(s)/2; k >= 1; k--) {
    vi ps(SZ(s) + 1, 0);
    for (int i = 0, j = i + k; j < SZ(s); i++, j++)
      ps[i + 1] = (s[i] == s[j] || s[i] == '?' || s[j] == '?') ? ps[i] + 1 : 0;
    for (int i = k; i < SZ(ps); i++)
      if (ps[i] - ps[i - k] == k) {
        cout << k*2 << ENDL;
        return;
      }
  }

  cout << 0 << ENDL;
}

signed main() { __
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}