#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  auto ask = [&](int x, int y) -> int {
    cout << "? " << x << ' ' << y << endl;
    int z;
    cin >> z;
    return z;
  };
  
  int n;
  // meterse en el ciclo -> a
  // preguntar a n -> k
  // preguntar a n - k -> b
  // respuesta ! b k
  cin >> n;
  int a = ask(n, 1);

  int k = ask(n, a);
  if(n == k){
    cout << "! " << n << ' ' << a << endl;
    return 0;
  }
  int b = ask(n - k, a);
  cout << "! " << k << ' ' << b << endl;

  return 0;
}