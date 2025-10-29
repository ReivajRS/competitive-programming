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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, k;
  cin >> n >> k;

  int lc, pc, lm, pm;
  cin >> lc >> pc >> lm >> pm;

  int t, d;
  cin >> t >> d;

  vi a(n);
  FOR (i, 0, n) {
    cin >> a[i];
  }

  sort(a.rbegin(), a.rend());

  vector<ll> extra(n + 1, 0), extra_c(n + 1, 0), extra_m(n + 1, 0);
  vector<ll> need_c(n + 1, 0), need_m(n + 1, 0);
  vi can_c(n + 1, 0), can_m(n + 1, 0);
  FOR (i, 0, n) {;
    extra[i + 1] = extra[i] + (a[i] > d ? d : a[i] - 1);
    extra_c[i + 1] = extra_c[i] + max(0, min(a[i] - lc, min(d, a[i] - 1)));
    extra_m[i + 1] = extra_m[i] + max(0, min(a[i] - lm, min(d, a[i] - 1)));
    need_c[i + 1] = need_c[i] + max(0, lc - a[i]);
    need_m[i + 1] = need_m[i] + max(0, lm - a[i]);
    can_c[i + 1] = can_c[i] + (lc - a[i] <= d);
    can_m[i + 1] = can_m[i] + (lm - a[i] <= d);
  }

  ll mn = 1e16;
  for (ll i = 0; i < n; i++) {
    if (can_c[i] < i) {
      continue;
    }
    ll r = max(i, n - ((k - 1) * i));
    ll extra_t = (extra[n] - extra[r]) + (extra_m[r] - extra_m[i]) + extra_c[i];
    if (need_c[i] > extra_t) {
      continue;
    }
    ll cost = 0;
    cost += i * pc;
    cost += need_c[i] * t;
    if (can_m[r] - can_m[i] < r - i) {
      continue;
    }
    if (need_m[r] - need_m[i] > extra_t - need_c[i]) {
      continue;
    }
    cost += (r - i) * pm;
    cost += (need_m[r] - need_m[i]) * t;
    mn = min(mn, cost);
  }

  if (mn != (ll) 1e16) {
    cout << mn << ENDL;
  }
  else {
    cout << -1 << ENDL;
  }

  return 0;
}