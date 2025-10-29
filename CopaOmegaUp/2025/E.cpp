#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
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
  
  vector<int> h(4);
  for (int i = 0; i < 4; i++) {
    cin >> h[i];
  }
  sort(h.begin(), h.end());

  cout << abs((h[0] + h[3]) - (h[1] + h[2])) << '\n';
  
  return 0;
}