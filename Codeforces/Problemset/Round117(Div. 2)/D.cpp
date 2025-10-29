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
 * Hashing
 * Descripcion: El objetivo es convertir una cadena en un numero entero
 * para poder comparar cadenas en O(1)
 * Tiempo: O(|s|)
 */

const int MX = 1e5 + 2;  // Tamano maximo del string S

inline int add(int a, int b, const int &mod) { return a + b >= mod ? a + b - mod : a + b; }
inline int sbt(int a, int b, const int &mod) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b, const int &mod) { return 1ll * a * b % mod; }

const int X[] = {257, 359};
const int MOD[] = {(int)1e9 + 7, (int)1e9 + 9};
vector<int> xpow[2];

struct hashing {
  vector<int> h[2];

  hashing(string &s) {
    int n = s.size();
    for (int j = 0; j < 2; ++j) {
      h[j].resize(n + 1);
      for (int i = 1; i <= n; ++i) {
        h[j][i] = add(mul(h[j][i - 1], X[j], MOD[j]), s[i - 1], MOD[j]);
      }
    }
  }
  
  ll value(int l, int r) { // hash [i, j)
    int a = sbt(h[0][r], mul(h[0][l], xpow[0][r - l], MOD[0]), MOD[0]);
    int b = sbt(h[1][r], mul(h[1][l], xpow[1][r - l], MOD[1]), MOD[1]);
    return (ll(a) << 32) + b;
  }
};

// Llamar la funcion antes del hashing
void calc_xpow(int mxlen = MX) {
  for (int j = 0; j < 2; ++j) {
    xpow[j].resize(mxlen + 1, 1);
    for (int i = 1; i <= mxlen; ++i) {
      xpow[j][i] = mul(xpow[j][i - 1], X[j], MOD[j]);
    }
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  string s1, s2;
  cin >> s1 >> s2;

  if (SZ(s1) < SZ(s2)) {
    swap(s1, s2);
  }

  calc_xpow();

  hashing h1(s1), h2(s2);

  int cnt = 0;

  for (int sz = 1; sz <= SZ(s2); sz++) {
    if (SZ(s1) % sz != 0 || SZ(s2) % sz != 0) {
      continue;
    }
    ll h = h2.value(0, sz);
    int l = SZ(s1) / sz;
    bool flag = 1;
    for (int c = 0, i = 0; c < l; c++, i += sz) {
      if (h != h1.value(i, i + sz)) {
        flag = 0;
      }
    }
    l = SZ(s2) / sz;
    for (int c = 0, i = 0; c < l; c++, i += sz) {
      if (h != h2.value(i, i + sz)) {
        flag = 0;
      }
    }
    cnt += flag;
  }
  
  cout << cnt << ENDL;
  
  return 0;
}