#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) begin(x),end(x)
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i,a,b) for(int i = (int)a - 1; i>= (int)b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

int eval(vi a, vi b, vi has) {
  int ans = 0, ptr = 0;
  FOR (i, 0, SZ(a)) {
    if (ptr < SZ(b) && a[i] == b[ptr]) {
      ptr++;
      continue;
    }
    ans += 1 + (has[a[i]]);
  }
  return ans;
}

signed main() { __
  int n, m;
  cin >> n >> m;

  vi a(n), b(m);
  for (auto &ai : a) {
    cin >> ai;
  }
  for (auto &bi : b) {
    cin >> bi;
  }

  int n2, m2;
  cin >> n2 >> m2;
  vi c(n2), d(m2), in_c(n + m + 10, 0), in_d(n + m + 10, 0);
  for (auto &ci : c) {
    cin >> ci;
    in_c[ci] = 1;
  }
  for (auto &di : d) {
    cin >> di;
    in_d[di] = 1;
  }
  reverse(ALL(b));
  reverse(ALL(d));
  int ans = eval(a, c, in_c) + eval(b, d, in_d);
  cout << ans << ENDL;

  return 0;
}