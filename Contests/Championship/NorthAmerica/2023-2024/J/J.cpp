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

  int n;
  ll p;
  cin >> n >> p;
  vector<ll> a(n);
  vector<__int128_t> b(n);
  FOR (i, 0, n) {
    cin >> a[i];
    b[i] = a[i];
  }
  __int128_t suma = 0;
  FOR (i, 0, n) {
    __int128_t quito = suma + (b[i] - 1) * i;
    if (-quito < b[i] - p) {
      cout << i << ENDL;
      return 0;
    }
    suma += b[i];
  }
  cout << n << ENDL;
  return 0;
}