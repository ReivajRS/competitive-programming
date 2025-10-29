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

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n;
  cin >> n;

  vi a(n);
  for (auto &x : a) cin >> x;

  vi b(5);
  for (auto &x : b) cin >> x;

  vector<ll> c(5, 0);
  ll money = 0;

  for (auto &x : a) {
    money += x;
    ROF (i, 5, 0) {
      if (money >= b[i]) {
        c[i] += money / b[i];
        money %= b[i];
      }
    }
  }

  for (auto &x : c) cout << x << ' ';
  cout << ENDL;
  cout << money << ENDL;
  
  return 0;
}