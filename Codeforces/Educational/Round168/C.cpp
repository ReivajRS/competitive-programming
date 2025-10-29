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

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  // blanks
  // 
  // opening
  // 
  // closing
  // 
  // (())(())

  int ans = 0;
  stack<int> blanks, opening, closing;
  FOR (i, 0, n) {
    if (s[i] == '_') {
      if (!opening.empty()) {
        s[i] = ')';
        ans += i - opening.top();
        // cout << opening.top() << ' ' << i << ENDL;
        opening.pop();
      } else {
        blanks.push(i);
      }
    }
    else if (s[i] == '(') {
      opening.push(i);
    }
    else if (s[i] == ')') {
      if (!blanks.empty()) {
        s[blanks.top()] = '(';
        ans += i - blanks.top();
        // cout << blanks.top() << ' ' << i << ENDL;
        blanks.pop();
      }
    }
  }

  // cout << s << ENDL;
  cout << ans << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  
  return 0;
}