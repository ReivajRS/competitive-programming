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

vi PI(const vi& a) {
  vi p(SZ(a));
  FOR(i, 1, SZ(a)) {
    int g = p[i - 1];
    while (g && a[i] != a[g]) g = p[g - 1];
    p[i] = g + (a[i] == a[g]);
  }
  return p;
}

int KMP(const vi& a, const vi& pat) {
  vi phi = PI(pat);
  int matches = 0;
  for (int i = 0, j = 0; i < SZ(a); ++i) {
    while (j > 0 && a[i] != pat[j]) j = phi[j - 1];
    if (a[i] == pat[j]) ++j;
    if (j == SZ(pat)) {
      matches++;
      j = phi[j - 1];
    }
  }
  return matches;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n, m;
  cin >> n >> m;

  vi a(n), b(m);

  FOR (i, 0, n) {
    cin >> a[i];
  }

  FOR (i, 0, m) {
    cin >> b[i];
  }

  FOR (i, 0, n) {
    a.pb(a[i]);
  }

  if (KMP(a, b) > 0) {
    cout << 1 << ENDL;
    return 0;
  }

  a.resize(n);

  int l = n - 1, r = 1;  
  while (l > r) {
    swap(a[l], a[r]);
    l--, r++;
  }

  FOR (i, 0, n) {
    a.pb(a[i]);
  }

  if (KMP(a, b) > 0) {
    cout << 1 << ENDL;
    return 0;
  }

  cout << 0 << ENDL;

  return 0;
}