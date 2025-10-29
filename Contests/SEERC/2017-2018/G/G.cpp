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
#define ROF(i, a, b) for (int i = (int)a-1; i >= (int)b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

double dist(double v, double a, double t) {
  return v*t + 0.5*a*t*t;
}

signed main() { __
  int n;
  cin >> n;
  vi a(n), s(n);
  FOR (i, 0, n) {
    cin >> a[i] >> s[i];
  }

  double v = 0, d1 = 0, d2 = 0;

  FOR (i, 0, n) {
    d1 += dist(v, a[i], s[i]);
    v += a[i]*s[i];
  }

  vi p(n);
  iota(ALL(p), 0);
  sort(ALL(p), [&](int i, int j) {
    return a[i] > a[j];
  }); 

  v = 0;

  FOR (i, 0, n) {
    d2 += dist(v, a[p[i]], s[p[i]]);
    v += a[p[i]]*s[p[i]];
  }

  cout << setprecision(1) << fixed;
  cout << d2 - d1 << ENDL;

  return 0;
}