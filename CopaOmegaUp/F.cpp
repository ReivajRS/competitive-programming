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

signed main() { __
  int n;
  cin >> n;

  set<string> st1, st2;
  map<string, string> mp;

  FOR (i, 0, n - 1) {
    string s1, s2;
    cin >> s1 >> s2;
    st1.insert(s1), st2.insert(s2);
    mp[s2] = s1;
  }

  for (auto &x : st1) {
    st2.erase(x);
  }
  
  string ft = *st2.begin();

  while (1) {
    cout << ft << ENDL;
    ft = mp[ft];
    if (ft == "")
      break;
  }

  return 0;
}