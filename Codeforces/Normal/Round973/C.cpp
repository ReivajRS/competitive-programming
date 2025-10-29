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

/*
  0100
  0   -> si   0000
  1   -> si   0000
  11  -> no
  00  -> si
  000 -> no

  001 -> no
  100 -> si
  0010
  0100

  0100
  ? 0
  ? 1
  ? 01  -> si
  ? 001 -> no
  ? 0001 -> no
  ! 01xx
  ? 00  -> si
  ! 0100


  1100
  ? 0
  ? 1
  ? 00  -> si
  ? 000 -> no
  ? 11  -> si
  ? 1100
  ? 0011

  101101
  ? 0
  ? 1
  ? 00 -> no
  ? 11 -> si
  ? 111 -> no
  ? 01  -> si
  ? 10  -> si


  0110
  ? 0
  ? 1
  ? 00 -> no
  ? 11 -> si
  ? 111 -> no
  ! 0110

  1010101
  ? 0
  ? 1
  ? 00 -> no
  ? 11 -> no
  ? 1010101
  ? 0101010
  ! 1010101

  00111010001
  ? 0
  ? 1
  ? 00 -> si
  ? 000 -> si
  ? 0000 -> no
  ? 11 -> si
  ? 111 -> si
  ? 1111 -> no
  
  111000
  11101000
  1110101000
  1110011000
  1110001000
  1110111000

  ? 11101000 -> si
  ? 1011101000 -> no
  ? 0011101000 -> si
  ? 00111010001 -> si
  ! 00111010001

*/

void solve() {
  int n;
  cin >> n;
  bool zero = false, one = false;
  int ans;
  cout << "? 0" << endl;
  cin >> ans;
  zero = ans;
  cout << "? 1" << endl;
  cin >> ans;
  one = ans;
  if (zero && !one) {
    cout << "! " << string(n, '0') << endl;
    return;
  }
  if (!zero && one) {
    cout << "! " << string(n, '1') << endl;
    return;
  }
  int cnt = 2;
  int mx0 = 1, mx1 = 1;
  while (cnt < 2 * n) {
    cnt++;
    cout << "? " << string(mx0 + 1, '0') << endl;
    cin >> ans;
    if (!ans)
      break;
    mx0++;
  }
  while (cnt < 2 * n) {
    cnt++;
    cout << "? " << string(mx1 + 1, '1') << endl;
    cin >> ans;
    if (!ans)
      break;
    mx1++;
  }
  string s0 = string(mx0, '0'), s1 = string(mx1, '1');
  while (cnt < 2 * n) {
    cout << "? " << s0 << s1 << endl;
    cin >> ans;
    if (ans) {
      while (1) {
        cnt++;
        cout << "? " << s0;
        FOR (i, 0, (n - mx0 - mx1) / 2) {
          cnt++;
          cout << "01";
        }
        cout << s1 << endl;
      }
    }
    cout << "? " << s1 << s0 << endl;
    cin >> ans;
  }
  assert(0);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int tc;
  cin >> tc;
  while(tc--) {
    solve();
  }
  
  return 0;
}