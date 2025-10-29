#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vi PI(const string& s) {
  vi p(SZ(s));
  FOR(i, 1, SZ(s)) {
    int g = p[i - 1];
    while (g && s[i] != s[g]) g = p[g - 1];
    p[i] = g + (s[i] == s[g]);
  }
  return p;
}

signed main() { __
  string s;
  cin >> s;

  int n = SZ(s);
  vi pi = PI(s), c(n + 1);;

  for (int i = 0; i < n; i++)
    c[pi[i]]++;
  for (int i = n-1; i > 0; i--)
    c[pi[i-1]] += c[i];
  for (int i = 0; i <= n; i++)
    c[i]++;

  int i = pi[n - 1];
  while (i > 0) {
    if (c[i] >= 3) {
      cout << s.substr(0, i) << ENDL;
      return 0;
    }
    i = pi[i - 1];
  }

  cout << "Just a legend" << ENDL;

  return 0;
}