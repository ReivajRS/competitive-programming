#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<pi> cond(5);
  FOR (i, 0, 5) {
    char c1, s, c2;
    cin >> c1 >> s >> c2;
    if (s == '>') swap(c1, c2);
    cond[i] = {c1 - 'A', c2 - 'A'};
  }

  vi perm = {0, 1, 2, 3, 4};
  do {
    vi p(5);
    FOR (i, 0, 5) {
      p[perm[i]] = i;
    }
    bool good = 1;
    for (auto &[c1, c2] : cond) {
      if (p[c1] > p[c2]) {
        good = 0;
        break;
      }
    }
    if (!good) continue;
    FOR (i, 0, 5) {
      cout << char('A' + perm[i]);
    }
    cout << ENDL;
    return 0;
  } while (next_permutation(ALL(perm)));
  cout << "impossible" << ENDL;

  return 0;
}