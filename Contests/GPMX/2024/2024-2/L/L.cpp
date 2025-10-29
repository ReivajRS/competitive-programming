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

  /* Note: 
      a and b have the position where value x is in a or b
      a2 and b2 have the value at each position
  */

  vi a(1000001), b(1000001);
  vi a2(n), b2(n);
  
  FOR (i, 0, n) {
    int x;
    cin >> x;
    a[x] = i;
    a2[i] = x;
  }
  
  FOR (i, 0, n) {
    int x;
    cin >> x;
    b[x] = i;
    b2[i] = x;
  }
  
  int cnt = 0;

  FOR (i, 0, n) {
    if (a[i + 1] == i)
      continue;
    int x = a[i + 1];
    a[i + 1] = i;
    a[a2[i]] = x;
    cnt++;
    swap(a2[i], a2[x]);
  }

  FOR (i, 0, n) {
    if (b[i + 1] == i)
      continue;
    int x = b[i + 1];
    b[i + 1] = i;
    b[b2[i]] = x;
    cnt++;
    swap(b2[i], b2[x]);
  }

  cout << cnt << ENDL;

  return 0;
}