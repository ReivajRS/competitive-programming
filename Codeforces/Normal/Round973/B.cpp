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

/*
  3 2 4 5 4
  3 2   1 4
  3 -1    4
  -4      4
          8
*/

/*
  4 3 2 1 5
  4 3 -1  5
  -8      5
*/

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &x : a) {
    cin >> x;
  }
  ll act = a[n - 2];
  for (int i = n - 3; i >= 0; i--) {
    act -= a[i];
  }
  cout << a.back() - act << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int tc;
  cin >> tc;
  while(tc--) {
    solve();
  }
  
  return 0;
}