#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a-1; i >= (int)b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main() { __
  int n;
  cin >> n;

  int ones = 0, two = 0;
  FOR (i, 0, n) {
    int x;
    cin >> x;
    ones += x == 1;
    two += x == 2;
  }

  if (ones == n - 1) {
    cout << "Win";
    return 0;
  }
  if (ones == n - 2) {
    if (n % 3 == 2 || !two) {
      cout << "Lose";
      return 0;  
    }
    cout << "Win";
    return 0;
  }
  if (ones == n) {
    if (n % 3 == 0) {
      cout << "Lose";
      return 0;  
    }
    cout << "Win";
    return 0;
  }
  cout << "Lose";
  return 0;
}