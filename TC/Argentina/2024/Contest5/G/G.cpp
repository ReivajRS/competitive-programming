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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  string s = to_string(n);

  ll mx = 0, val = 1;
  for (char c : s) {
    val *= c - '0';
  }

  mx = max(mx, val);

  vector<ll> pot(SZ(s) + 5, 1);
  pot[0] = 1;
  FOR (i, 1, SZ(s) + 1) {
    pot[i] *= pot[i - 1] * 9;
  }

  val = 1;
  FOR (i, 0, SZ(s)) {
    if (s[0] == '1') {
      mx = max(mx, pot[SZ(s) - i - 1]);
      continue;
    }
    mx = max(mx, val * (s[i] - '0' - 1) * pot[SZ(s) - i - 1]);
    val *= s[i] - '0';
  }

  cout << mx << ENDL;

  return 0;
}