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

void solve(string &s) {
  ll cnt = 0;
  ll pos = 0, neg = 0;

  FOR (i, 0, SZ(s)) {
    if (s[i] == '+') {
      if (neg > 0) {
        neg--;
        cnt--;        
      }
      pos++;
      cnt++;
    }
    if (s[i] == '-') {
      if (pos > 0) {
        pos--;
        cnt--;
      }
      cnt++;
      neg++;
    }
  }

  cout << cnt << ENDL;
}

signed main() { __
  string s;

  while (cin >> s) {
    solve(s);
  }

  return 0;
}