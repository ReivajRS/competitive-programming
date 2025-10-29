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

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int k, n;
  cin >> k >> n;

  int cnt = 1;
  string s = "X";
  for (int i = 0; i < k; i++) {
    int len = n - SZ(s);
    int x = len / 3;
    if (cnt + x == k) {
      for (int j = 0; j < x; j++) {
        s += "--X";
      }
      cnt += x;
      break;
    }
    cnt++;
    s += "-X";
  }

  if (cnt != k || SZ(s) < n - 2 || SZ(s) > n) {
    cout << "*" << ENDL;
    return 0;
  }

  if (SZ(s) <= n - 1) {
    cout << "-";
  }

  cout << s;

  if (SZ(s) == n - 2) {
    cout << "-";
  }

  cout << ENDL;
  
  return 0;
}