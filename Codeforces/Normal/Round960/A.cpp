#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

void solve() {
  int n;
  cin >> n;
  map<int, int> mp;
  FOR (i, 0, n) {
    int x;
    cin >> x;
    mp[x]++;
  }
  if (mp.rbegin()->second & 1) {
    cout << "YES" << ENDL;
    return;
  }
  int mx = mp.rbegin()->first;
  for (auto &[k, v] : mp) {
    if (k == mx)
      break;
    if (v & 1) {
      cout << "YES" << ENDL;
      return;
    }
  }
  cout << "NO" << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  
  return 0;
}