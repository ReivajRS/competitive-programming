#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<ll>;

#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vi a(10);

  FOR (i, 0, 10) {
    cin >> a[i];
  }

  ll x, y;
  cin >> x >> y;

  ll sum = 0;
  for (int i = 0; i < 10; i+=2) {
    sum += a[i] * a[i + 1];
  }
  sum /= 5;

  sum *= x;
  sum /= y;

  cout << sum << ENDL;

  return 0;
}