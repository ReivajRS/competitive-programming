#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i,a,b) for(int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'

int n, x;

void check(vi ans) {
  FOR (i, 0, SZ(ans)-1) if (ans[i] + ans[i + 1] == x) {
    cout << "*\n";
    exit(0);
  }
  FOR (i, 0, SZ(ans)) cout << ans[i] << " \n"[i==SZ(ans)-1];
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> x;
  vi a(n);
  FOR(i, 0,n) cin >> a[i];

  sort(ALL(a));

  int cnt_half = 0;
  if (x % 2 == 0) FOR (i, 0, n) cnt_half += a[i]==x/2;

  if (cnt_half == 1) {
    FOR (i, 0, n) cout << a[i] << " \n"[i==n-1];
    return 0;
  }

  vi lo, hi;
  FOR (i, 0, n) {
    if (a[i]* 2 < x) lo.pb(a[i]);
    else if (a[i] * 2 > x) hi.pb(a[i]);
  }

  if (cnt_half > 1) {
    int ptr_lo = 0, ptr_hi, half = x / 2;
    vi ans;
    ans.pb(half);
    cnt_half -= 2;
    while (cnt_half) {
      if (ptr_lo < SZ(lo)) {
        ans.pb(lo[ptr_lo]);
        ptr_lo++; 
      } else if (ptr_hi < SZ(hi)) {
        ans.pb(hi[ptr_hi]);
        ptr_hi++; 
      } else {
        cout << "*\n";
        return 0;
      }
    }
    while (ptr_lo < SZ(lo)) {
      ans.pb(lo[ptr_lo]);
      ptr_lo++; 
    }
    ans.pb(half);
    while (ptr_hi < SZ(hi)) {
      ans.pb(lo[ptr_hi]);
      ptr_hi++; 
    }
    check(ans);
    FOR (i, 0, n) cout << ans[i] << " \n"[i == n -1];
    return 0;
  }

  if (lo[0] != lo.back()) swap(lo[0], lo[SZ(lo)-1]);
  if (hi[0] != hi.back()) swap(hi[0], hi[SZ(hi)-1]);
  
  vi ans;
  for (auto &x :lo)ans.pb(x);
  for (auto &x :hi)ans.pb(x);

  check(ans);

  return 0;
}