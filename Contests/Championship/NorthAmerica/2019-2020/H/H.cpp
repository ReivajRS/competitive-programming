#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i,a,b) for(int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'

/*
 * Evil Hashing
 * Descripcion: utiliza aritmetica modulo 2^64 - 1, el doble de lento
 * que mod 2^64 y con mas codigo, pero funciona bien con casos
 * malvados (como Thue-Morse, donde ABBA... y BAAB... de longitud
 * 2^10 tienen el mismo hash mod 2^64)
 * Utilizar "using H = ull;" si se cree que los casos son aleatorios,
 * o trabaja mod 10^9+7 si la paradoja del cumpleanos no es un problema. 
 * Utiliza cosas de c++20.
 * Uso:
 *  Normal.
 *     string s;
 *     HashInterval hi(s);
 *     hi.hashInterval(0, 5);
 *  Rabin-Karp.
 *     string s;
 *     getHashes(s, SZ(s));
 *     ....
 * Tiempo: O(|s|)
 */

using ull = uint64_t ;
struct H {
	ull x; H(ull x=0) : x(x) {}
	H operator+(H o) { return x + o.x + (x + o.x < x); }
	H operator-(H o) { return *this + ~o.x; }
	H operator*(H o) { auto m = (__uint128_t)x * o.x;
		return H((ull)m) + (ull)(m >> 64); }
	ull get() const { return x + !~x; }
	bool operator==(H o) const { return get() == o.get(); }
	bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (ll)1e11+3; // (order ~ 3e9; random also ok)

struct HashInterval {
	vector<H> ha, pw;
	HashInterval(string& str) : ha(SZ(str)+1), pw(ha) {
		pw[0] = 1;
		FOR (i,0,SZ(str))
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
	}
	H hashInterval(int a, int b) { // hash [a, b)
		return ha[b] - ha[a] * pw[b - a];
	}
};

vector<H> getHashes(string& str, int length) {
	if (SZ(str) < length) { 
    return {};
  }
	H h = 0, pw = 1;
	FOR (i, 0, length) {
		h = h * C + str[i];
    pw = pw * C;
  }
  vector<H> ret = {h};
	FOR (i, length, SZ(str)) {
		ret.push_back(h = h * C + str[i] - pw * str[i-length]);
	}
	return ret;
}

H hashString(string& s){
  H h{}; 
  for (char c : s) {
    h = h * C + c;
  };
  return h;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<string> s(3);
  cin >> s[0] >> s[1] >> s[2];
  int n = SZ(s[0]);
  s[0] += s[0], s[1] += s[1], s[2] += s[2];

  int ans = 1e9;

  vector<HashInterval> h = {HashInterval(s[0]),HashInterval(s[1]),HashInterval(s[2])};

  FOR (fijado, 0, 3) {
    // cout << fijado << ENDL;
    FOR (i, 0, n) {
      bool good = 1;
      FOR (k, 0, n) if (s[0][k] == s[1][i+k]) {
        good = 0;
        break;
      }
      if (!good) continue;
      string complement = "";
      FOR (k, 0, n) {
        int suma = s[0][k] - 'A' + s[1][i+k] - 'A';
        if (suma == 1) complement += "C";
        else if (suma == 2) complement += "B";
        else complement += "A";
      }
      H hash = hashString(complement);
      // cout << " " << i << ' ' << complement << ' ' << hash.get() << ENDL;
      FOR (j, 0, n) {
        // cout << "  " << j << ' ' << h[2].hashInterval(j, j + n).get() << ENDL;
        if (hash.x == h[2].hashInterval(j, j + n).x) {
          // cout << "papu" << ENDL;
          ans = min(ans, min(i, n - i) + min(j, n - j));
        }
      }
    }
    if (fijado == 0) {
      swap(s[0], s[1]);
      swap(h[0], h[1]);
    } else {
      swap(s[0], s[2]);
      swap(h[0], h[2]);
    }
  }
  if (ans == 1e9) ans = -1;
  cout << ans << ENDL;
  return 0;
}