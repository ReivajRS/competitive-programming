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

string w[5][5];

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  w[0][0] = w[0][2] = "***";
  w[0][1] = w[0][3] = w[0][4] = "*.*";
  
  w[1][0] = w[1][2] = w[1][4] = "***";
  w[1][1] = w[1][3] = "*.*";

  w[2][0] = w[2][4] = "***";
  w[2][1] = w[2][2] = w[2][3] = "*..";

  w[3][0] = w[3][4] = "***";
  w[3][1] = w[3][2] = w[3][3] = "*.*";

  w[4][0] = w[4][2] = w[4][4] = "***";
  w[4][1] = w[4][3] = "*..";

  int n;
  string s;
  cin >> n >> s;

  FOR (k, 0, 5) {
    for (auto &si : s) {
      cout << w[si - 'A'][k];
    }
    cout << ENDL;
  }

  return 0;
}