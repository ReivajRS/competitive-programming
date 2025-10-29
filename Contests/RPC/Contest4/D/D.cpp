#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i,a,b) for (int i = (int)a;i<(int)b;++i)

signed main() {
  string s, t;
  cin >> s >> t;

  char vs = '#', vt = '#';
  reverse(ALL(t));
  
  vector<bool> is_vowel(300, 0);
  is_vowel['a'] = is_vowel['e'] = is_vowel['i'] = is_vowel['o'] = is_vowel['u'] = 1;

  string cs = "", ct = "";
  cs += s[0];
  ct += t[0];
  FOR (i, 1, SZ(s)) {
    if (is_vowel[s[i]]) {
      vs = s[i];
      break;
    }
    cs += s[i];
  }
  FOR (i, 1, SZ(t)) {
    if (is_vowel[t[i]]) {
      vt = t[i];
      break;
    }
    ct += t[i];
  }

  reverse(ALL(ct));

  string ans = cs;
  if (vt != '#') {
    ans += vt;
  } else if (vs != '#') {
    ans += vs;
  } else {
    ans += 'o';
  }
  ans += ct;
  cout << ans << '\n';

  return 0;
}