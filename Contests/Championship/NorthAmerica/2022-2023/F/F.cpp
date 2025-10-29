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

  int sum = 0;

  vector<pi> lados(4);
  FOR (i, 0, 4) {
    cin >> lados[i].first >> lados[i].second;
    sum += lados[i].first * lados[i].second;
  }

  int lado = sqrt(sum);
  if (lado * lado != sum) {
    cout << 0 << ENDL;
    return 0;
  }

  sort(ALL(lados));
  vi perm = {0,1,2,3};

  #define x first
  #define y second

  auto check = [&](vector<pi> l) -> bool {
    if (
      l[0].x + l[1].x == lado
      && l[2].x + l[3].x == lado
      && l[0].y + l[2].y == lado
      && l[1].y + l[3].y == lado
    ) return true;
    
    if (
      l[0].x + l[1].x + l[2].x == lado && l[2].x == l[3].x
      && l[0].y == l[1].y && l[0].y == l[2].y + l[3].y
      && l[0].y == lado
    ) return true;

    if (
      l[0].x + l[1].x == lado && l[1].x == l[2].x && l[2].x == l[3].x
      && l[0].y == l[1].y + l[2].y + l[3].y
      && l[0].y == lado
    ) return true;

    if (
      l[0].x + l[1].x + l[2].x + l[3].x == lado
      && l[0].y == l[1].y && l[1].y == l[2].y && l[2].y == l[3].y
      && l[0].y == lado
    ) return true;

    if (
      l[0].x == lado && l[1].x + l[2].x == lado
      && l[2].x == l[3].x
      && l[0].y + l[2].y + l[3].y == lado
      && l[0].y + l[1].y == lado
    ) return true;

    return false;
  };

  do {
    for (int msk = 0; msk < (1 << 4); msk++) {
      vector<pi> l;
      FOR(i,0,4) l.pb(lados[perm[i]]);
      FOR (i, 0, 4) {
        if (msk & (1 << i))
          swap(l[i].first, l[i].second);
      }
      if (check(l)) {
        cout << 1 << ENDL;
        return 0;
      }
    }
  } while(next_permutation(ALL(perm)));

  cout << 0 << ENDL;

  return 0;
}