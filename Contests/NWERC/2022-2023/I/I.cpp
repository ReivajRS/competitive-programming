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

signed main() { __
  int l, r;
  cin >> l >> r;

  vi ans(3, 0);

  FOR (i, l, r + 1) {
    string s;
    cin >> s;
    if (s == "FizzBuzz") {
      ans[2] = gcd(ans[3], i);
    }
    if (s == "Fizz") {
      ans[0] = gcd(ans[0], i);
    }
    if (s == "Buzz") {
      ans[1] = gcd(ans[1], i);
    }
  }

  ans[0] = gcd(ans[0], ans[2]);
  ans[1] = gcd(ans[1], ans[2]);

  if (ans[0] == 0)
    ans[0] = r + 1;
  if (ans[1] == 0)
    ans[1] = r + 2;

  cout << ans[0] << ' ' << ans[1] << ENDL;

  return 0;
}