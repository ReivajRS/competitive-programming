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

constexpr int MOD = 998244353;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vi a(n);
  for (auto &ai : a) cin >> ai;

  int ans = 1;
  FOR (i, 0, n) {
    ans = 1ll * ans * (a[i] + 1) % MOD;
  }
  ans = (ans - 2 + MOD) % MOD;
  cout << ans << ENDL;

  return 0;
}