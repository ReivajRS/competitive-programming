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

double ans[] = {0.300000000, 1.500000000, -1, 0.500000000, 0.000001000, 0.017543860, 0.555555556, 0.600000000, -1, 0.198307495, -1};

void solve(double val) {
  int n;
  cin >> n;
  bool f = true;
  int y[2];
  for (int i = 1; i <= n; i++) {
    cin >> y[0] >> y[1];
    double yi = val * i;
    cout << yi << ENDL;
    if (y[0] > yi || y[1] < yi) {
      f = false;
    }
  }
  if ((f && val != -1) || (!f && val == -1)) {
    cout << "PASSED" << ENDL;
  }
  else {
    cout << "FAILED" << ENDL;
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; i++) {
    solve(i);
  }
  
  return 0;
}