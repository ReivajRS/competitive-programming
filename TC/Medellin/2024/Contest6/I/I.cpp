#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

bool llentar(vector<vi> &a, pi p1, pi p2, ll sumaBuena) {
  swap(a[p1.first][p1.second], a[p2.first][p2.second]);
  FOR(i, 0, SZ(a)) {
    ll sumaFila = 0;
    ll sumaCol = 0;
    FOR(j, 0, SZ(a)) {
      sumaFila += a[i][j];
      sumaCol += a[j][i];
    }

    if (sumaFila != sumaBuena) {
      swap(a[p1.first][p1.second], a[p2.first][p2.second]);
      return false;
    }
    if (sumaCol != sumaBuena) {
      swap(a[p1.first][p1.second], a[p2.first][p2.second]);
      return false;
    }
  }
  swap(a[p1.first][p1.second], a[p2.first][p2.second]);
  return true;
}

bool llentar2(vector<vi> &a, pi p1, pi p2) {
  swap(a[p1.first][p1.second], a[p2.first][p2.second]);
  set<ll> st;
  FOR(i, 0, SZ(a)) {
    ll sumaFila = 0;
    ll sumaCol = 0;
    FOR(j, 0, SZ(a)) {
      sumaFila += a[i][j];
      sumaCol += a[j][i];
    }
    st.insert(sumaFila);
    st.insert(sumaCol);
  }
  swap(a[p1.first][p1.second], a[p2.first][p2.second]);
  return SZ(st) == 1;
}

bool intentar3(vector<vi> &a,pi p1,pi p2,ll col1,ll col2,ll sumaBuena){
  swap(a[p1.first][p1.second], a[p2.first][p2.second]);

    ll suma1 = 0;
    ll suma2 = 0;
  FOR(i, 0, SZ(a)) {
    suma1 += a[i][col1];
    suma2+=a[i][col2];

    
  }

  if (suma1 != sumaBuena) {
      swap(a[p1.first][p1.second], a[p2.first][p2.second]);
      return false;
    }
    if (suma2 != sumaBuena) {
      swap(a[p1.first][p1.second], a[p2.first][p2.second]);
      return false;
    }

  swap(a[p1.first][p1.second], a[p2.first][p2.second]);
  return true;
}



bool intentar4(vector<vi> &a,pi p1,pi p2,ll col1,ll col2,ll sumaBuena){
  swap(a[p1.first][p1.second], a[p2.first][p2.second]);

    ll suma1 = 0;
    ll suma2 = 0;
  FOR(i, 0, SZ(a)) {
    suma1 += a[col1][i];
    suma2+=a[col2][i];

    
  }

  if (suma1 != sumaBuena) {
      swap(a[p1.first][p1.second], a[p2.first][p2.second]);
      return false;
    }
    if (suma2 != sumaBuena) {
      swap(a[p1.first][p1.second], a[p2.first][p2.second]);
      return false;
    }

  swap(a[p1.first][p1.second], a[p2.first][p2.second]);
  return true;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  map<ll, ll> mapa;
  ll n;
  cin >> n;
  vector<vi> a(n, vi(n, 0));

  FOR(i, 0, n) {
    ll suma = 0;
    FOR(j, 0, n) {
      cin >> a[i][j];
      suma += a[i][j];
    }
    mapa[suma]++;
  }

  FOR(i, 0, n) {
    ll suma = 0;
    FOR(j, 0, n) {
      suma += a[j][i];
    }
    mapa[suma]++;
  }

  if (n <= 5) {
    FOR(i, 0, n) {
      FOR(j, 0, n) {
        FOR(ii, 0, n) {
          FOR(jj, 0, n) {
            pi p1 = {i, j}, p2 = {ii, jj};
            if (p1 == p2) continue;
            if (p1 > p2) swap(p1, p2);
            if (llentar2(a, p1, p2)) {
              cout << p1.first + 1 << " " << p1.second + 1 << ENDL;
              cout << p2.first + 1 << " " << p2.second + 1 << ENDL;
              return 0;
            }
          }
        }
      }
    }
  } else {
    ll mx = 0, sumaBuena = 0;
    for (auto [x, y] : mapa) {
      if (y > mx) {
        sumaBuena = x;
        mx = y;
      }
    }

    vi filasMalas, columMala;

    FOR(i, 0, n) {
      ll sumaFila = 0;
      ll sumaCol = 0;
      FOR(j, 0, n) {
        sumaFila += a[i][j];
        sumaCol += a[j][i];
      }

      if (sumaFila != sumaBuena) {
        filasMalas.pb(i);
      }
      if (sumaCol != sumaBuena) {
        columMala.pb(i);
      }
    }

    if (!SZ(filasMalas)) {
      FOR(i, 0, n) {
        if(intentar3(a,{i,columMala[0]},{i,columMala[1]},columMala[0],columMala[1],sumaBuena)){
          pi ra = {i + 1, columMala[0] + 1}, rb{i + 1, columMala[1] + 1};
          if (ra > rb) swap(ra, rb);
          cout << ra.first << " " << ra.second << ENDL;
          cout << rb.first << " " << rb.second << ENDL;          
          return 0;
        }
      }
    } else if (!SZ(columMala)) {
      FOR(i, 0, n) {
        if(intentar4(a,{filasMalas[0],i},{filasMalas[1],i},filasMalas[0],filasMalas[1],sumaBuena)){
          pi ra = {filasMalas[0] + 1,i+1}, rb{filasMalas[1] + 1,i+1};
          if (ra > rb) swap(ra, rb);
          cout << ra.first << " " << ra.second << ENDL;
          cout << rb.first << " " << rb.second << ENDL;          
          return 0;
        }
      }
    } else {
      pi ra, rb;
      if (llentar2(a, {filasMalas[0], columMala[0]}, {filasMalas[1], columMala[1]})) {
        ra = {filasMalas[0] + 1, columMala[0] + 1}, rb = {filasMalas[1] + 1, columMala[1] + 1};
      } else if (llentar2(a, {filasMalas[1], columMala[0]}, {filasMalas[0], columMala[1]})) {
        ra = {filasMalas[1] + 1, columMala[0] + 1}, rb = {filasMalas[0] + 1, columMala[1] + 1};
      } 
      if (ra > rb) swap(ra, rb);
      cout << ra.first << " " << ra.second << ENDL;
      cout << rb.first << " " << rb.second << ENDL;
      return 0;
    }
  }
  assert(false);

  return 0;
}