#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)(x).size())

void solve() {
  ll n, k;
  cin >> n >> k;

  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  ll ans = 1;
  ll mx = *max_element(a.begin(), a.end());

  /*
    La respuesta es al menos 1 y como maximo n

    El maximo inicial es el minimo número de grupos que habrá

    La suma de las cantidades de todas las cartas excluyendo a la
    de mayor ocurrencia tiene que ser al menos igual

    Si mx > suma, respuesta = 1
    Si mx < suma

    mx tiene que dividir la suma

    3 2 2 2

    9 / 3 = 3

    [1, 2, 3]
    [1, 2, 4]
    [1, 3, 4]







    2 6 1 2 4
    suma = 15
    extra = 4
    max = 6

    [L, R]
    [15, 19]

    15 / 6 = 2, 19 / 6 = 3

    6, 12, 18
    7, 14
    8, 16
    9, 18
    10
    ...
    19

    viendo por grupos de tamaño k
    19 / 1 = 19
    19 / 2 = 9
    19 / 3 = 6
    19 / 4 = 4
    
    
    
    7 4 6 6 9 3 10 2 8 7
    suma = 62
    extra = 8
    max = 10

    [L, R]


    10, 20, 30, 40, 50, 60, 70
    11, 22, 33, 44, 55, 66
    12, 24, 36, 48, 60
    13, 26, 39, 52, 65
    14, 28, 42, 56, 70
    15, 30, 45, 60


    viendo por grupos de tamaño k
    70 / 1 = 70
    70 / 2 = 35
    70 / 3 = 23
    70 / 4 = 17
    70 / 5 = 14
    70 / 6 = 11
    70 / 7 = 10
    70 / 8 = 8
    70 / 9 = 7
    70 / 10 = 7
  */

  ll sum = accumulate(a.begin(), a.end(), 0ll);
  ll max_sum = sum + k;
  
  for (ll i = 1; i <= n; i++) {
    ll d = max_sum / i;
    if (d < mx) {
      break;
    }
    if (d * i >= sum) {
      ans = i;
    }
  }

  cout << ans << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  cin >> tc;

  while (tc--) {
    solve();
  }
  
  return 0;
}