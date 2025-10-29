#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for (int i = (int)a-1; i >= (int)b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0);

using vp = vector<pair<char, int>>;

vp compress(string s) {
  s += "#";
  vp ans;
  int cnt = 0;
  char lc = s[0];
  for (auto &c : s) {
    if (c != lc) {
      ans.pb({lc, cnt});
      lc = c;
      cnt = 1;
      continue;
    }
    cnt++;
  }
  return ans;
}

signed main() { __
  string s, t;
  getline(cin, s);
  getline(cin, t);

  vp vs = compress(s), vt = compress(t);
  unordered_set<char> bad;
  FOR (i, 0, SZ(vs)) {
    auto [c1, s1] = vs[i];
    auto [c2, s2] = vt[i];
    if (s1 != s2) {
      bad.insert(c1);
    }
  }

  for (auto &c : bad) {
    cout << c;
  }
  cout << ENDL;

  return 0;
}