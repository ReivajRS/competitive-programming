#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main() {
  int k, p;
  cin >> k >> p;

  string s;
  cin >> s;

  while (k--) {
    string aux = "";
    for (int i = 0; i < SZ(s); i += 2){
      int times = s[i] - '0';
      while (times--) {
        aux += s[i + 1];
      }
    }
    s = aux;
  }
  cout << s[p] << ENDL;

  return 0;
}