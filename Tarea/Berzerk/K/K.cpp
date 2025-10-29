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

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n;
  cin >> n;

  map<int, int> mp;
  FOR (i, 0, n) {
    int x;
    cin >> x;
    mp[x]++;
  }

  int mx = mp.rbegin()->first;
  bool win = mp[mx] & 1;

  for (auto &[k, v] : mp) {
    if (k == mx)
      break;
    if (v & 1) {
      win = 1;
      break;
    }
  }

  cout << (win ? "Conan" : "Agasa") << ENDL;
  
  return 0;
}