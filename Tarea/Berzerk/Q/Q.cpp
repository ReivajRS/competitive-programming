#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

double binpow(double a, int b) {
  if (!b) return 1;
  double x = binpow(a, b >> 1);
  return x * x * (b & 1 ? a : 1);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  double ev = 0;

  FOR (x, 1, n + 1) {
    ev += x * (binpow(1.0 * x / n, m) - binpow(1.0 * (x - 1) / n, m));
  }

  cout << setprecision(12) << fixed << ev << ENDL;
  
  return 0;
}