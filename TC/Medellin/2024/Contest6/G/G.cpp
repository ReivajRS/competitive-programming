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

vi nums;

void f(int l, int r, int x) {
  if (l > r) {
    nums.pb(x);
    return;
  }
  f(l + 1, r - 1, x);
  x |= 1 << r;
  x |= 1 << l;
  f(l + 1, r - 1, x);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  FOR (i, 0, 31) {
    f(0, i, 1 | (1 << i));
  }
  sort(ALL(nums));
  nums.erase(unique(ALL(nums)), nums.end());

  int q;
  cin >> q;

  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << upper_bound(ALL(nums), r) - lower_bound(ALL(nums), l) << ENDL;
  }

  return 0;
}